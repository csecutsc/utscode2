#!/usr/bin/env python3

import fractions
from random import randint, shuffle


def solve(pop, rate, food):
    years = 0
    while pop <= food:
        pop *= rate
        years += 1
    return years


RAND_PARAMS = [
    (2000, 10**9, 100, 10**9),
    (2000, 10, 10, 10**9),
    (2000, 10, 1000000, 10**9),
    (2000, 1000, 1000, 10**9),
    (2000, 1000000, 10, 10**9),
    (2000, 10**9, 100, 10000),
]

SPECIAL_NUMS = [
    2, 3, 18, 500, 387420488, 387420489, 536870911, 536870912, 5*(10**8), 10**9]


caseid = 2

for T, pmax, rmax, fmax in RAND_PARAMS:

    cases = []
    # hand cases
    for p in [1] + SPECIAL_NUMS:
        for r in SPECIAL_NUMS:
            for f in [1] + SPECIAL_NUMS:
                cases.append((p, r, f))
    # random cases
    while len(cases) < T:
        p = randint(1, pmax)
        r = randint(2, rmax)
        f = randint(1, fmax)
        cases.append((p, r, f))
    shuffle(cases)

    assert len(cases) == T

    with open('secret/{}.in'.format(caseid), 'w') as infile:
        infile.write('{}\n'.format(len(cases)))
        for p, r, f in cases:
            infile.write('{} {} {}\n'.format(p, r, f))

    with open('secret/{}.ans'.format(caseid), 'w') as ansfile:
        for p, r, f in cases:
            ansfile.write(str(solve(p, r, f)) + '\n')

    caseid += 1
