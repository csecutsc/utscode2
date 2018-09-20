#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    R, C = map(int, input().split())
    if R == 0 and C == 0:
        print(0)
        continue

    W = 1
    H = 1
    d = False
    while R >= H or C >= W:
        if not d:
            W *= 2
        else:
            H *= 2
        d = not d

    v = W * H // 2
    if d:
        W //= 2
        C -= W
        v += C * H + R
    else:
        H //= 2
        R -= H
        v += R * W + C

    print(v)

