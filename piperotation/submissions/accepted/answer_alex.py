#!/usr/bin/env python3

def solve():
    R, C = map(int, input().split())
    G = [list(input().strip()) for _ in range(R)]
    right = [[False for c in range(C)] for r in range(R)]
    down = [[False for c in range(C)] for r in range(R)]
    for i in range(R):
        for j in range(C):
            r = right[i][j - 1] if j > 0 else False
            d = down[i - 1][j] if i > 0 else False
            if G[i][j] == 'A':
                if r or d:
                    return "Impossible"
                right[i][j] = down[i][j] = False
            if G[i][j] == 'B':
                if r == d:
                    return "Impossible"
                right[i][j] = r
                down[i][j] = d
            if G[i][j] == 'C':
                right[i][j] = not r
                down[i][j] = not d
            if G[i][j] == 'D':
                if (not r) or (not d):
                    return "Impossible"
                right[i][j] = down[i][j] = True

    for i in range(R):
        if right[i][C - 1]:
            return "Impossible"
    for j in range(C):
        if down[R - 1][j]:
            return "Impossible"
    return "Possible"


print(solve())
