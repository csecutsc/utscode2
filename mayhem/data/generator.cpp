#define DEBUG 0

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

// Random number in range [lo, hi] for nonnegative lo and hi.
int rand(int lo, int hi) {
  return ((rand() & 0x7fff) | ((rand() & 0x7fff) << 15)) % (hi - lo + 1) + lo;
}

string name(int num, string ext) {
  stringstream ss;
  ss << num;
  string str;
  ss >> str;
  return "secret/" + str + ext;
}

/*** VERIFIER ***/

/*** GENERATOR ***/

const int MAXR = 2000;
const int MAXC = 2000;

void gen(int num, int R, int C, double x_rate) {
  assert(0 <= x_rate && x_rate <= 1);
  assert(1 <= R && R <= MAXR);
  assert(1 <= C && C <= MAXC);
  ofstream fout(name(num, ".in").c_str());
  fout << R << " " << C << endl;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if ((double)rand() / RAND_MAX < x_rate) {
        fout << "x";
      } else {
        fout << ".";
      }
    }
    fout << endl;
  }
  fout.close();
}

void gen(int num, const vector<string> &g) {
  int R = g.size(), C = g[0].size();
  assert(1 <= R && R <= MAXR);
  assert(1 <= C && C <= MAXC);
  ofstream fout(name(num, ".in").c_str());
  fout << R << " " << C << endl;
  for (int i = 0; i < R; i++) {
    assert((int)g[i].size() == C);
    fout << g[i] << endl;
  }
  fout.close();
}

void gen_diag(int num, int R, int C, int extra = 0) {
  vector<string> g(R, string(C, '.'));
  for (int i = 0; i < R && i < C; i++) {
    g[i][i] = 'x';
  }
  while (extra > 0) {
    int r = rand(0, R - 1), c = rand(0, C - 1);
    if (g[r][c] != 'x') {
      g[r][c] = 'x';
      extra--;
    }
  }
  ofstream fout(name(num, ".in").c_str());
  fout << R << " " << C << endl;
  for (int i = 0; i < R; i++) {
    fout << g[i] << endl;
  }
  fout.close();
}

string rep(const string &s, int n) {
  string res;
  for (int i = 0; i < n; i++) {
    res += s;
  }
  return res;
}

vector<string> rep(const vector<string> &v, int n) {
  vector<string> res;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)v.size(); j++) {
      res.push_back(v[j]);
    }
  }
  return res;
}

void gen() {
  int t = 2;
  gen(t++, 5, 5, 0.10);
  gen(t++, 5, 5, 0.30);
  gen(t++, 5, 5, 0.80);
  gen(t++, 10, 10, 0.06);
  gen(t++, 10, 10, 0.15);
  gen(t++, 10, 10, 0.80);
  gen(t++, 100, 100, 0.02);
  gen(t++, 100, 100, 0.80);
  gen(t++, 500, 500, 0.001);
  gen(t++, rep({rep("x.", 1000), rep(".x", 1000)}, 1000));
  gen(t++, rep({rep("x..", 333), rep(".x.", 333), rep("..x", 333)}, 333));
  gen(t++, 1500, 1999, 0.0001);
  gen(t++, 1999, 2000, 0.001);
  gen(t++, 2000, 1999, 0.0015);
  gen(t++, 2000, 2000, 0.9999);
  gen(t++, 2000, 2000, 1.00);
  gen_diag(t++, 2000, 2000, 4);
  gen_diag(t++, 2000, 2000, 150);
  gen_diag(t++, 2000, 2000, 1500);
}

/*** SOLVER ***/

int R, C, total, components;
char G[MAXR][MAXC];
int lcol[MAXR][MAXC], rcol[MAXR][MAXC];
int urow[MAXR][MAXC], drow[MAXR][MAXC];

void init_pointers() {
  memset(lcol, -1, sizeof lcol);
  memset(rcol, -1, sizeof rcol);
  memset(urow, -1, sizeof urow);
  memset(drow, -1, sizeof drow);
  int curr;
  for (int i = 0; i < R; i++) {
    curr = -1;
    for (int j = 0; j < C; j++) {
      if (G[i][j] == 'x') {
        lcol[i][j] = curr;
        curr = j;
      }
    }
    curr = -1;
    for (int j = C - 1; j >= 0; j--) {
      if (G[i][j] == 'x') {
        rcol[i][j] = curr;
        curr = j;
      }
    }
  }
  for (int j = 0; j < C; j++) {
    curr = -1;
    for (int i = 0; i < R; i++) {
      if (G[i][j] == 'x') {
        urow[i][j] = curr;
        curr = i;
      }
    }
    curr = -1;
    for (int i = R - 1; i >= 0; i--) {
      if (G[i][j] == 'x') {
        drow[i][j] = curr;
        curr = i;
      }
    }
  }
}

void update_pointers(int r, int c) {
  if (lcol[r][c] != -1) {
    if (rcol[r][c] != -1) {
      rcol[r][lcol[r][c]] = rcol[r][c];
      lcol[r][rcol[r][c]] = lcol[r][c];
    } else {
      rcol[r][lcol[r][c]] = -1;
    }
  }
  if (urow[r][c] != -1) {
    if (drow[r][c] != -1) {
      drow[urow[r][c]][c] = drow[r][c];
      urow[drow[r][c]][c] = urow[r][c];
    } else {
      drow[urow[r][c]][c] = -1;
    }
  }
  if (rcol[r][c] != -1) {
    if (lcol[r][c] != -1) {
      lcol[r][rcol[r][c]] = lcol[r][c];
      rcol[r][lcol[r][c]] = rcol[r][c];
    } else {
      lcol[r][rcol[r][c]] = -1;
    }
  }
  if (drow[r][c] != -1) {
    if (urow[r][c] != -1) {
      urow[drow[r][c]][c] = urow[r][c];
      drow[urow[r][c]][c] = drow[r][c];
    } else {
      urow[drow[r][c]][c] = -1;
    }
  }
}

void flood(int r, int c) {
  queue<pair<int, int>> q;
  for (q.push(make_pair(r, c)); !q.empty(); q.pop()) {
    r = q.front().first;
    c = q.front().second;
    if (G[r][c] == '.') {
      continue;
    }
    total++;
    G[r][c] = '.';
    update_pointers(r, c);
    if (lcol[r][c] != -1) q.push(make_pair(r, lcol[r][c]));
    if (urow[r][c] != -1) q.push(make_pair(urow[r][c], c));
    if (rcol[r][c] != -1) q.push(make_pair(r, rcol[r][c]));
    if (drow[r][c] != -1) q.push(make_pair(drow[r][c], c));
  }
}

int solve(ifstream &fin) {
  total = components = 0;
  fin >> R >> C;
  assert(1 <= R && R <= MAXR);
  assert(1 <= C && C <= MAXC);
  for (int i = 0; i < R; i++) {
    fin >> G[i];
  }
  init_pointers();
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (G[i][j] == 'x') {
        flood(i, j);
        components++;
      }
    }
  }
  printf("R: %d, C: %d, total: %d, components: %d\n", R, C, total, components);
  return total - components;
}

int main() {
  srand(0xDEADBEEF);
  // GENERATE
  gen();

  // SOLVE
  for (int num = 0; num <= 100; num++) {
    ifstream fin(name(num, ".in").c_str());
    if (!fin.good()) continue;
    int ans = solve(fin);
    cout << ans << endl;
    ofstream fout(name(num, ".ans").c_str());
    fout << ans << endl;
    fout.close();
  }
  return 0;
}
