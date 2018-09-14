#define DEBUG 0

#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

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

template<class T> T rand_select(const std::set<T> &s) {
  double r = rand() % s.size();
  typename std::set<T>::iterator it = s.begin();
  for (; r != 0; r--) it++;
  return *it;
}

void gen(int num, int R, int C, int swaps = 0, bool swap_adj = 0) {
  vector<string> G(R, string(C, ' '));
  vector<vector<bool>> right(R, vector<bool>(C, 0));
  vector<vector<bool>> down(R, vector<bool>(C, 0));

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      bool r = j ? right[i][j - 1] : false;
      bool d = i ? down[i - 1][j] : false;

      set<char> options{'A', 'B', 'C', 'D'};

      if (r || d) {
        options.erase('A');
      }
      if (r == d) {
        options.erase('B');
      }
      if (!r || !d) {
        options.erase('D');
      }
      if (j == C - 1) {
        if (r) {
          options.erase('B');
        } else {
          options.erase('C');
        }
        options.erase('D');
      }
      if (i == R - 1) {
        if (d) {
          options.erase('B');
        } else {
          options.erase('C');
        }
        options.erase('D');
      }

      assert(!options.empty());

      G[i][j] = rand_select(options);
      switch (G[i][j]) {
        case 'A': {
          right[i][j] = down[i][j] = false;
          break;
        }
        case 'B': {
          right[i][j] = r;
          down[i][j] = d;
          break;
        }
        case 'C': {
          right[i][j] = !r;
          down[i][j] = !d;
          break;
        }
        case 'D': {
          right[i][j] = down[i][j] = true;
          break;
        }
      }
    }
  }

  int r1, c1, r2, c2;
  for (int i = 0; i < swaps; i++) {
    r1 = rand(0, R - 1);
    c1 = rand(0, C - 1);
    if (swap_adj) {
      if (rand()) {
        r2 = (r1 + 1) % R;
        c2 = c1;
      } else {
        r2 = r1;
        c2 = (c1 + 1) % C;
      }
    } else {
      r2 = rand(0, R - 1);
      c2 = rand(0, C - 1);
    }
    swap(G[r1][c1], G[r2][c2]);
  }

  ofstream fout(name(num, ".in").c_str());
  fout << R << " " << C << endl;
  for (int i = 0; i < R; i++) {
    fout << G[i] << endl;
  }
  fout.close();
}

void gen() {
  int t = 10;
  gen(t++, 5, 5);
  gen(t++, 10, 10);
  gen(t++, 20, 20);
  gen(t++, 50, 50);
  gen(t++, 50, 50, 1, 0);
  gen(t++, 50, 50, 1, 1);
  gen(t++, 50, 50, 50, 0);
  gen(t++, 50, 50, 50, 1);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 1, 0);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 1, 1);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 5, 0);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 5, 1);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 10, 0);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 10, 1);
  gen(t++, 100, 100);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 50, 0);
  gen(t++, 100, 100, 50, 1);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 200, 0);
  gen(t++, 100, 100, 200, 1);
  gen(t++, 100, 100);
  gen(t++, 100, 100, 1000, 0);
  gen(t++, 100, 100, 1000, 1);
  gen(t++, 100, 100);
}

/*** SOLVER ***/

string solve(ifstream &fin) {
  const int LIM = 101;
  int R, C;
  char G[LIM][LIM];
  bool right[LIM][LIM] = {0}, down[LIM][LIM] = {0};
  fin >> R >> C;
  for (int i = 0; i < R; i++) {
    fin >> G[i];
  }
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      bool r = j ? right[i][j - 1] : false;
      bool d = i ? down[i - 1][j] : false;
      if (G[i][j] == 'A') {
        if (r || d) {
          return "Impossible";
        }
        right[i][j] = down[i][j] = false;
      }
      if (G[i][j] == 'B') {
        if (r == d) {
          return "Impossible";
        }
        right[i][j] = r;
        down[i][j] = d;
      }
      if (G[i][j] == 'C') {
        right[i][j] = !r;
        down[i][j] = !d;
      }
      if (G[i][j] == 'D') {
        if (!r || !d) {
          return "Impossible";
        }
        right[i][j] = down[i][j] = true;
      }
    }
  }
  for (int i = 0; i < R; i++) {
    if (right[i][C - 1]) {
      return "Impossible";
    }
  }
  for (int j = 0; j < C; j++) {
    if (down[R - 1][j]) {
      return "Impossible";
    }
  }
  return "Possible";
}

int main() {
  srand(0xDEADBEEF);
  // GENERATE
  gen();

  // SOLVE
  for (int num = 0; num <= 100; num++) {
    ifstream fin(name(num, ".in").c_str());
    if (!fin.good()) continue;
    string ans = solve(fin);
    cout << "Case " << num << ": " << ans << endl;
    ofstream fout(name(num, ".ans").c_str());
    fout << ans << "\n";
    fout.close();
  }
  return 0;
}
