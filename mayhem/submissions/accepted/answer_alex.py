#!/usr/bin/env python3

from collections import deque

R, C = map(int, input().split())
G = [list(input().strip()) for _ in range(R)]

total = 0
components = 0

# Initialize pointers.
lcol = [[-1 for c in range(C)] for r in range(R)]
rcol = [[-1 for c in range(C)] for r in range(R)]
urow = [[-1 for c in range(C)] for r in range(R)]
drow = [[-1 for c in range(C)] for r in range(R)]

for i in range(R):
    curr = -1
    for j in range(C):
        if G[i][j] == 'x':
            lcol[i][j] = curr
            curr = j
    curr = -1
    for j in range(C - 1, -1, -1):
        if G[i][j] == 'x':
            rcol[i][j] = curr
            curr = j

for j in range(C):
    curr = -1
    for i in range(R):
        if G[i][j] == 'x':
            urow[i][j] = curr
            curr = i
    curr = -1
    for i in range(R - 1, -1, -1):
        if G[i][j] == 'x':
            drow[i][j] = curr
            curr = i


def update_pointers(r, c):
    if lcol[r][c] != -1:
        if rcol[r][c] != -1:
            rcol[r][lcol[r][c]] = rcol[r][c];
            lcol[r][rcol[r][c]] = lcol[r][c];
        else:
            rcol[r][lcol[r][c]] = -1;

    if urow[r][c] != -1:
        if drow[r][c] != -1:
            drow[urow[r][c]][c] = drow[r][c];
            urow[drow[r][c]][c] = urow[r][c];
        else:
            drow[urow[r][c]][c] = -1;

    if rcol[r][c] != -1:
        if lcol[r][c] != -1:
            lcol[r][rcol[r][c]] = lcol[r][c];
            rcol[r][lcol[r][c]] = rcol[r][c];
        else:
            lcol[r][rcol[r][c]] = -1;

    if drow[r][c] != -1:
        if urow[r][c] != -1:
            urow[drow[r][c]][c] = urow[r][c];
            drow[urow[r][c]][c] = drow[r][c];
        else:
            urow[drow[r][c]][c] = -1;


q = deque()

for i in range(R):
    for j in range(C):
        if G[i][j] == 'x':
            components += 1
            q.append((i, j))
            while q:
                r, c = q.popleft()
                if G[r][c] == '.':
                    continue
                total += 1
                G[r][c] = '.'
                update_pointers(r, c)
                if lcol[r][c] != -1: q.append((r, lcol[r][c]))
                if urow[r][c] != -1: q.append((urow[r][c], c))
                if rcol[r][c] != -1: q.append((r, rcol[r][c]))
                if drow[r][c] != -1: q.append((drow[r][c], c))

print(total - components)
