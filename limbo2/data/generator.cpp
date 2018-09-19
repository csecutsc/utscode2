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

vector<int> vals{0, 1, 2, 4, 8, 1000, 65534, 1048575, 33554432, 536870911, 536870912, 1000000000};

void gen() {
  vector<pair<int, int>> cases;
  for (int i = 0; i < vals.size(); i++) {
    for (int j = i; j < vals.size(); j++) {
      int a = vals[i];
      int b = vals[j];
      if (rand() % 2) {
        cases.push_back(make_pair(a, b));
      } else {
        cases.push_back(make_pair(a, b));
      }
    }
  }
  while (cases.size() < 100) {
    int a = rand(0, 1e9);
    int b = rand(0, 1e9);
    cases.push_back(make_pair(a, b));
  }
  random_shuffle(cases.begin(), cases.end());
  ofstream fout(name(2, ".in").c_str());
  assert(cases.size() <= 100);
  fout << cases.size() << endl;
  for (int i = 0; i < cases.size(); i++) {
    fout << cases[i].first << " " << cases[i].second << endl;
  }
  fout.close();
}

/*** SOLVER ***/

long long solve(long long R, long long C) {
  if (R == 0 && C == 0) {
    return 0;
  }
  long long W = 1, H = 1;
  bool d = false;
  while (R >= H || C >= W) {
    if (!d) {
      W *= 2;
    } else {
      H *= 2;
    }
    d = !d;
  }
  long long ans = W*H / 2;
  if (d) {
    W /= 2;
    C -= W;
    ans += C*H + R;
  } else {
    H /= 2;
    R -= H;
    ans += R*W + C;
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
    ofstream fout(name(num, ".ans").c_str());
    int T;
    fin >> T;
    for (int i = 1; i <= T; i++) {
      long long r, c;
      fin >> r >> c;
      long long ans = solve(r, c);
      fout << ans << endl;
      cout << "Case " << i << ": (" << r << ", " << c << ") -> " << ans << endl;
    }
    fin.close();
    fout.close();
  }
  return 0;
}
