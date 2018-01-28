#!/usr/bin/env python3
r, d = map(int, input().split())
print(int(r * (r + 1) / 2 + (d -1)*r + (d - 2)*(d - 1) / 2))
