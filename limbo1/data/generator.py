#!/usr/bin/env python3
from random import randint, shuffle

def genfile(data, infile, outfile):
    with open(infile, 'w') as f:
        f.write('{}\n'.format(len(data)))
        for l, r in data:
            f.write(str(l) + ' ' + str(r) + '\n')

    with open(outfile, 'w') as f:
        for l, r in data:
            f.write(str(l*(l - 1)//2 + l*(r + 1) + (r + 1)*(r + 2)//2) + '\n')

genfile([(1, 2), (2, 3), (5, 8)],
        'sample/{}.in'.format(1), 'sample/{}.ans'.format(1))

data = [(0, 0), (0, 1), (0, 2), (0, 10**9), (1, 0), (1, 1), (1, 2), (1, 10**9),
        (2, 0), (2, 1), (2, 2), (2, 10**9), (10**9, 0), (10**9, 1), (10**9, 2),
        (10**9, 10**9)]
T = 100
for i in range(T - len(data)):
    exponent = randint(0, 9)
    l = randint(0, 10**exponent)
    r = randint(0, 10**exponent)
    data.append((l, r))

shuffle(data)
genfile(data, 'secret/{}.in'.format(2), 'secret/{}.ans'.format(2))
