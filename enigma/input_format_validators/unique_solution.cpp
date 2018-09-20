#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
using namespace std;

int sy, sx;
char grid[22][22];
int lenH[22][22], lenV[22][22];
int uH[22][22], uV[22][22];
int n;
char word[200][22];
int len[200];
int i, j, k;
char tmp[22];

bool found = false;

void rec(int i) {
  // Done?
  if (i == n) {
    for (j = 0; j < sy; j++) {
      printf("%s\n", grid[j]);
    }
    assert(!found);
    found = true;
  }
  // Place next word horizontally.
  bool chg[21];
  for (int y = 0; y < sy; y++) {
    for (int x = 0; x + len[i] - 1 < sx; x++) {
      if (lenH[y][x] == len[i] && !uH[y][x]) {
        // Check validity.
        for (j = 0; j < len[i]; j++) {
          if (grid[y][x + j] != '.' && grid[y][x + j] != word[i][j]) break;
        }
        // Try it.
        if (j == len[i]) {
          // Place word.
          memset(chg, 0, sizeof chg);
          for (j = 0; j < len[i]; j++)
            if (grid[y][x + j] == '.') {
              grid[y][x + j] = word[i][j];
              chg[j] = 1;
            }
          uH[y][x] = 1;
          // Recurse.
          rec(i + 1);
          // Remove word.
          uH[y][x] = 0;
          for (j = 0; j < len[i]; j++) {
            if (chg[j]) {
              grid[y][x + j] = '.';
            }
          }
        }
      }
    }
  }
  // Place next word vertically.
  for (int y = 0; y + len[i] - 1 < sy; y++) {
    for (int x = 0; x < sx; x++) {
      if (lenV[y][x] == len[i] && !uV[y][x]) {
        // Check validity.
        for (j = 0; j < len[i]; j++)
          if (grid[y + j][x] != '.' && grid[y + j][x] != word[i][j]) break;
        // Try it.
        if (j == len[i]) {
          // Place word.
          memset(chg, 0, sizeof chg);
          for (j = 0; j < len[i]; j++) {
            if (grid[y + j][x] == '.') {
              grid[y + j][x] = word[i][j];
              chg[j] = 1;
            }
          }
          uV[y][x] = 1;
          // Recurse.
          rec(i + 1);
          // Remove word.
          uV[y][x] = 0;
          for (j = 0; j < len[i]; j++) {
            if (chg[j]) {
              grid[y + j][x] = '.';
            }
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d%d\n", &sy, &sx);
  for (i = 0; i < sy; i++) {
    scanf("%s\n", &grid[i]);
  }
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    scanf("%s\n", &word[i]);
    len[i] = strlen(word[i]);
  }
  // Sort the words by length.
  for (i = 0; i < n; i++) {
    for (j = 1; j < n; j++) {
      if (len[j - 1] < len[j]) {
        swap(len[j - 1], len[j]);
        memcpy(tmp, word[j - 1], sizeof tmp);
        memcpy(word[j - 1], word[j], sizeof tmp);
        memcpy(word[j], tmp, sizeof tmp);
      }
    }
  }
  // Precompute horizontal grid lengths.
  for (i = 0; i < sy; i++) {
    for (j = 0; j < sx; j++) {
      if (grid[i][j] == '.') {
        for (k = j + 1; k < sx && grid[i][k] == '.'; k++)
          ;
        lenH[i][j] = k - j;
        j = k;
      }
    }
  }
  // Precompute vertical grid lengths.
  for (i = 0; i < sx; i++) {
    for (j = 0; j < sy; j++) {
      if (grid[j][i] == '.') {
        for (k = j + 1; k < sy && grid[k][i] == '.'; k++)
          ;
        lenV[j][i] = k - j;
        j = k;
      }
    }
  }
  // DFS.
  rec(0);
  return 42;
}
