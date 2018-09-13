#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    r, d = map(int, input().strip().split())
    print(r*(r + 1)//2 + r*(d - 1) + (d - 2)*(d - 1)//2)
