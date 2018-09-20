#!/usr/bin/env python3

R, C = map(int, input().split())

def empty_grid():
    return [[False for c in range(C + 2)] for r in range(R + 2)]


G = empty_grid()
V = empty_grid()


def dfs1(r, c):
  if r < 1 or r > R or c < 1 or c > C or (not G[r][c]) or V[r][c]:
      return 0
  V[r][c] = True
  return 1 + \
        dfs1(r - 1, c) + dfs1(r + 1, c) + dfs1(r, c - 1) + dfs1(r, c + 1)


def dfs0(r, c):
  if r < 0 or r > R + 1 or c < 0 or c > C + 1 or G[r][c] or V[r][c]:
    return 0
  V[r][c] = True
  return 1 + dfs0(r - 1, c - 1) + dfs0(r - 1, c + 1) + dfs0(r + 1, c - 1) + \
             dfs0(r + 1, c + 1) + dfs0(r - 1, c) + dfs0(r + 1, c) + \
             dfs0(r, c - 1) + dfs0(r, c + 1)

ans = 0

for mask in range(1, 1 << (R*C)):
    r1 = -1
    c1 = -1
    r0 = -1
    c0 = -1
    G = empty_grid()
    for i in range(R):
        for j in range(C):
            bit = bool((mask >> (i*C + j)) & 1)
            G[i + 1][j + 1] = bit
            if bit and r1 == -1:
                r1 = i + 1
                c1 = j + 1
            elif (not bit) and r0 == -1:
                r0 = i + 1
                c0 = j + 1

    cnt1 = bin(mask).count('1')
    cnt0 = (R + 2)*(C + 2) - cnt1

    # Check that 1's are connected.
    V = empty_grid()
    if cnt1 != dfs1(r1, c1):
        continue

    # Check that 0's are connected.
    V = empty_grid()
    if r0 != -1 and cnt0 != dfs0(r0, c0):
        continue
    ans += 1

print(ans)
