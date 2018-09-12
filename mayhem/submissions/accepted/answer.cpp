#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int MAXR = 5005, MAXC = 5005;

int R, C, total = 0, components = 0;
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

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> G[i];
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
  cout << total - components << endl;
  return 0;
}
