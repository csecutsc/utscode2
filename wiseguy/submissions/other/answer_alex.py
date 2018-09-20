#!/usr/bin/env python3

LIM = 500

dyn = [[0.0 for c in range(LIM + 1)] for r in range(LIM + 1)]
tot = [[0.0 for c in range(LIM + 1)] for r in range(LIM + 1)]

dyn[0][0] = 1
dyn[1][0] = 1

for i in range(LIM + 1):
    if i >= 2:
        for a in range(i):
            b = i - a - 1
            for h3 in range(i):
                # h1 = h3, h2 <= h3
                dyn[i][h3 + 1] += dyn[a][h3]*tot[b][h3 + 1] // i
                # h1 < h3, h2 = h3
                dyn[i][h3 + 1] += tot[a][h3]*dyn[b][h3] // i

    for a in range(LIM):
        tot[i][a + 1] = tot[i][a] + dyn[i][a]

T = int(input())
for _ in range(T):
    N = int(input())
    for i in range(N):
        ans += i*dyn[N][i]
    print('{0:.9f}'.format(ans))
