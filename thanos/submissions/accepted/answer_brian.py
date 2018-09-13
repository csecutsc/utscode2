#!/usr/bin/env python3

T = int(input())

for _ in range(T):
    pop, rate, food = map(int, input().strip().split())
    years = 0
    while pop <= food:
        pop = int(pop*(1 + (rate/100)))
        years += 1
    print(years)
