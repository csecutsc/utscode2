#!/usr/bin/env python3

N = int(input())
O = [int(input()) for _ in range(N)]
ans = []

def move(i):
    global O
    O = O[i:N] + O[0:i][::-1]
    ans.append(i)

while True:
    e = 1
    for i in range(O.index(1), N - 1):
        if O[i + 1] != e + 1:
            break
        e += 1
    if e == N:
        break
    move(N)
    i = O.index(e)
    if i > 0:
        move(i)
    move(O.index(1) + 1)
    move(O.index(e + 1) + 1)

print(len(ans))
for num in ans:
    print(num)
