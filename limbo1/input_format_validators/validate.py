#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = stdin.readline()
assert re.match(integer + "\n", line), \
    "Expected a single integer, got {}".format(line)

for _ in range(int(line)):
    line = stdin.readline()
    assert re.match(integer + " " + integer + "\n", line), \
        "Expected a pair of integers, got {}.".format(line)
    R, D = map(int, line.split())
    assert 1 <= R <= 10**9, "R = {} must be in [1, 10^9]".format(R)
    assert 1 <= D <= 10**9, "D = {} must be in [1, 10^9]".format(D)

assert len(sys.stdin.readline()) == 0, "Extra lines detected after input."

sys.exit(42)
