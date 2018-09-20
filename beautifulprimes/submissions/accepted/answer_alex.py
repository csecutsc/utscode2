#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    N = int(input())
    for i in range(N + 1):
        v = 1
        for j in range(N):
            v *= (2 if j < i else 11)
        if len(str(v)) == N:
            for j in range(N):
                print(2 if j < i else 11, end=('\n' if j == N - 1 else ' '))
            break
