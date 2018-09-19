#define DEBUG 0

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
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

void gen(int num, int N) {
  ofstream fout(name(num, ".in").c_str());
  fout << N << endl;
  vector<int> a;
  for (int i = 1; i <= N; i++) {
    a.push_back(i);
  }
  // Knuth shuffle.
  for (int i = 0; i < N; i++) {
    int j = rand(i, N - 1);
    swap(a[i], a[j]);
  }
  for (int i = 0; i < N; i++) {
    fout << a[i] << endl;
  }
  fout.close();
}

void gen() {
  int t = 2;
  gen(t++, 1);
  gen(t++, 2);
  gen(t++, 3);
  gen(t++, 4);
  gen(t++, 10);
  gen(t++, 20);
  gen(t++, 50);
  gen(t++, 100);
  gen(t++, 200);
  gen(t++, 200);
  gen(t++, 200);
}

/*** SOLVER ***/

int N, O[200];
vector<int> ans;

void move(int x) {
  int j = 0, tmp[200];
  for (int i = x; i < N; i++) {
    tmp[j++] = O[i];
  }
  for (int i = x - 1; i >= 0; i--) {
    tmp[j++] = O[i];
  }
  memcpy(O, tmp, sizeof O);
  ans.push_back(x);
}

int find(int v) {
  for (int i = 0; i < N; i++) {
    if (O[i] == v) {
      return i;
    }
  }
  assert(false);
}

vector<int> solve(ifstream &fin) {
  ans.clear();
  fin >> N;
  for (int i = 0; i < N; i++) {
    fin >> O[i];
  }
  for (;;) {
    int e = 1;
    for (int i = find(1); i + 1 < N && O[i + 1] == e + 1; i++, e++);
    if (e == N) {
      break;
    }
    move(N);
    if (find(e)) {
      move(find(e));
    }
    move(find(1) + 1);
    move(find(e + 1) + 1);
  }
  return ans;
}

int main() {
  srand(0xDEADBEEF);
  // GENERATE
  gen();

  // SOLVE
  for (int num = 0; num <= 100; num++) {
    ifstream fin(name(num, ".in").c_str());
    if (!fin.good()) continue;
    vector<int> ans = solve(fin);
    ofstream fout(name(num, ".ans").c_str());
    fout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
      fout << ans[i] << endl;
    }
    fout.close();
  }
  return 0;
}

