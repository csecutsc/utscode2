#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct node {
  int x, y, dx, dy, l;
  bool operator<(const node &z) const { return x + y < z.x + z.y; }
};

bool cmp(const string &a, const string &b) { return a.size() < b.size(); }

int h, w, f, l0, l1, n, t;
int k[25];
string l[200];
bool b[200];
string a[25];
vector<node> v;

void recur(int p) {
  if (f) {
    return;
  }
  if (p == n) {
    for (l0 = 0; l0 < h; l0++) {
      cout << a[l0] << '\n';
    }
    f = 1;
    return;
  }
  bitset<25> u;
  int l2, l3, g;
  for (l2 = k[v[p].l]; l[l2].size() == v[p].l; l2++) {
    if (b[l2] == false) {
      g = 0;
      u.reset();
      for (l3 = 0; l3 < v[p].l; l3++) {
        if (a[v[p].x + l3*v[p].dx][v[p].y + l3*v[p].dy] == '.') {
          u[l3] = true;
          a[v[p].x + l3*v[p].dx][v[p].y + l3*v[p].dy] = l[l2][l3];
        } else if (a[v[p].x + l3*v[p].dx][v[p].y + l3*v[p].dy] !=
                   l[l2][l3]) {
          g = 1;
          break;
        }
      }
      if (g == 0) {
        recur(p + 1);
      }
      for (l3 = 0; l3 < v[p].l; l3++) {
        if (u[l3]) {
          a[v[p].x + l3*v[p].dx][v[p].y + l3*v[p].dy] = '.';
        }
      }
    }
  }
}

int main() {
  cin >> h >> w;
  for (l0 = 0; l0 < h; l0++) {
    cin >> a[l0];
  }
  for (l0 = 0; l0 < h; l0++) {
    for (l1 = 0; l1 < w; l1++) {
      if ((l0 == 0 || a[l0 - 1][l1] == '#') && l0 < h - 1 &&
          a[l0 + 1][l1] == '.' && a[l0][l1] == '.') {
        t = l0;
        while (a[t][l1] == '.') {
          t++;
        }
        v.push_back((node){l0, l1, 1, 0, t - l0});
      }
      if ((l1 == 0 || a[l0][l1 - 1] == '#') && l1 < w - 1 &&
          a[l0][l1 + 1] == '.' && a[l0][l1] == '.') {
        t = l1;
        while (a[l0][t] == '.') {
          t++;
        }
        v.push_back((node){l0, l1, 0, 1, t - l1});
      }
    }
  }
  sort(v.begin(), v.end());
  cin >> n;
  for (l0 = 0; l0 < n; l0++) {
    cin >> l[l0];
  }
  sort(l, l + n, cmp);
  k[l[0].size()] = 0;
  for (l0 = 1; l0 < n; l0++) {
    if (l[l0].size() != l[l0 - 1].size()) {
      k[l[l0].size()] = l0;
    }
  }
  f = 0;
  recur(0);
  return 0;
}
