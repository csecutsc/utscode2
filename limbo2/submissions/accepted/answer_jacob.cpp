#define DEBUG 0

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int, int>

#define Fox(i, n) for (i = 0; i < n; i++)
#define Fox1(i, n) for (i = 1; i <= n; i++)
#define FoxI(i, a, b) for (i = a; i <= b; i++)
#define FoxR(i, n) for (i = (n)-1; i >= 0; i--)
#define FoxR1(i, n) for (i = n; i > 0; i--)
#define FoxRI(i, a, b) for (i = b; i >= a; i--)
#define Foxen(i, s) for (i = s.begin(); i != s.end(); i++)
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(), (s).end()
#define Fill(s, v) memset(s, v, sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template <typename T>
T Abs(T x) {
  return (x < 0 ? -x : x);
}
template <typename T>
T Sqr(T x) {
  return (x * x);
}
string plural(string s) {
  return (Sz(s) && s[Sz(s) - 1] == 'x' ? s + "en" : s + "s");
}

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

#if DEBUG
#define GETCHAR getchar
#else
#define GETCHAR getchar_unlocked
#endif

bool Read(int &x) {
  char c, r = 0, n = 0;
  x = 0;
  for (;;) {
    c = GETCHAR();
    if ((c < 0) && (!r)) return (0);
    if ((c == '-') && (!r))
      n = 1;
    else if ((c >= '0') && (c <= '9'))
      x = x * 10 + c - '0', r = 1;
    else if (r)
      break;
  }
  if (n) x = -x;
  return (1);
}

int main() {
  if (DEBUG) freopen("in.txt", "r", stdin);
  int T;
  LL R, C, W, H, v;
  bool d;
  Read(T);
  while (T--) {
    scanf("%lld%lld", &R, &C);
    if ((!R) && (!C)) {
      printf("0\n");
      continue;
    }
    W = H = 1;
    d = 0;
    while ((R >= H) || (C >= W)) {
      if (!d)
        W *= 2;
      else
        H *= 2;
      d = !d;
    }
    v = W * H / 2;
    if (d) {
      W /= 2;
      C -= W;
      v += C * H + R;
    } else {
      H /= 2;
      R -= H;
      v += R * W + C;
    }
    printf("%lld\n", v);
  }
  return (0);
}
