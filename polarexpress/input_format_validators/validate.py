#!/usr/bin/env python3
import re
import sys

def answer_exists(N, O):
    ans = []

    def move(i):
        tmp = O[i:N] + O[0:i][::-1]
        O.clear()
        O.extend(tmp)
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

    return len(ans) <= 1000


integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + "\n", line), "'{}' is not an int".format(line)
N = int(line)
assert 1 <= N <= 200, "T = {} is not in [1, 200]".format(n, MAX)

vals = set()
O = []
cnt = 0
while True:
    line = sys.stdin.readline()
    if len(line) == 0:
        break
    assert re.match(integer + "\n", line), "'{}' is not an int".format(line)
    x = int(line)
    assert 1 <= x <= N, "{} is not in [1, {}]".format(1, N)
    cnt += 1
    vals.add(x)
    O.append(x)

assert len(vals) == N, "Values not a permutation of 1..{}".format(N)
assert cnt == N, "Number of lines ({}) not equal to N = {}".format(cnt, N)

assert answer_exists(N, O)

# Nothing to report.
sys.exit(42)

