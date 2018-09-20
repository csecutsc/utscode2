#!/usr/bin/env python3

from collections import deque

R, C = map(int, input().split())
G = [list(input().strip()) for _ in range(R)]

adj = [[[] for c in range(C)] for r in range(R)]

for i in range(R):
    p = -1
    for j in range(C):
        if G[i][j] == 'x':
            if p < 0:
                p = j
            else:
                adj[i][j].append((i, p))
                adj[i][p].append((i, j))

for j in range(C):
    p = -1
    for i in range(R):
        if G[i][j] == 'x':
            if p < 0:
                p = i
            else:
                adj[i][j].append((p, j))
                adj[p][j].append((i, j))

ans = 0
q = deque()

for i in range(R):
    for j in range(C):
        if G[i][j] == 'x':
            ans -= 1
            q.append((i, j))
            G[i][j] = '.'
            while q:
                r, c = q.popleft()
                ans += 1
                for r2, c2 in adj[r][c]:
                    if G[r2][c2] == 'x':
                        q.append((r2, c2))
                        G[r2][c2] = '.'

print(ans)
