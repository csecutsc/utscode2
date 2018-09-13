#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    r, d = map(int, input().strip().split())
    print(int(r * (r + 1) / 2 + (d -1)*r + (d - 2)*(d - 1) / 2))
