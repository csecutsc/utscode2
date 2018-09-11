#include <iostream>
using namespace std;

int R, C, total = 0, components = 0;
char G[5005][5005];

void flood(int r, int c) {
  total++;
  G[r][c] = '.';
  for (int i = r - 1; i >= 0; i--) {  // Building above?
    if (G[i][c] == 'x') {
      flood(i, c);
      break;
    }
  }
  for (int i = r + 1; i < R; i++) {  // Building below?
    if (G[i][c] == 'x') {
      flood(i, c);
      break;
    }
  }
  for (int j = c - 1; j >= 0; j--) {  // Building to the left?
    if (G[r][j] == 'x') {
      flood(r, j);
      break;
    }
  }
  for (int j = c + 1; j < C; j++) {  // Building to the right?
    if (G[r][j] == 'x') {
      flood(r, j);
      break;
    }
  }
}

int main() {
  cin >> R >> C;
  for (int i = 0; i < R; i++) {
    cin >> G[i];
  }
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
