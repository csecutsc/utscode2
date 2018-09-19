#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    L, R = map(int, input().strip().split())
    print(L*(L - 1)//2 + L*(R + 1) + (R + 1)*(R + 2)//2)
