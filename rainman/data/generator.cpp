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

void gen() {
  ofstream fout(name(2, ".in").c_str());
  fout << 50 << endl;
  for (int i = 0; i < 20; i++) {
    fout << rand(1, 100) << endl;
  }
  for (int i = 0; i < 30; i++) {
    fout << rand(100, 1000) << endl;
  }
  fout.close();
}

int main() {
  srand(0xDEADBEEF);
  // GENERATE
  gen();
  return 0;
}
