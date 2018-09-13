#include <iostream>
using namespace std;

long long hibit(long long x) {
  if (x == 0) {
    return 0;
  }
  x >>= 1;
  long long ret = 1;
  while (x > 0) {
    x >>= 1;
    ret <<= 1;
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    long long r, c;
    cin >> r >> c;

    long long hr = hibit(r);
    long long hc = hibit(c);

    if (hr >= hc) {
      cout << 2*hr*hr + (r - hr)*hr + c << endl;
    } else {
      cout << hc*hc + (c - hc)*hc + r << endl;
    }
  }
  return 0;
}
