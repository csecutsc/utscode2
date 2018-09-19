#!/usr/bin/env python3
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + "\n", line), \
    "Expected a single integer, got {}".format(line)
T = int(line)
assert 1 <= T <= 100, "T = {} is not in [1, 100]".format(n, MAX)

for _ in range(int(line)):
    line = sys.stdin.readline()
    assert re.match(integer + " " + integer + "\n", line), \
        "Expected a pair of integers, got {}.".format(line)
    L, R = map(int, line.split())
    assert 0 <= L <= 10**9, "D = {} must be in [0, 10^9]".format(D)
    assert 0 <= R <= 10**9, "R = {} must be in [0, 10^9]".format(R)

assert len(sys.stdin.readline()) == 0, "Extra lines detected after input."

sys.exit(42)
