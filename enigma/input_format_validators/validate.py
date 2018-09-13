#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + " " + integer + "\n", line), \
    "'{}' is not a pair of integers".format(line)

R, C = map(int, line.split())
assert 1 <= R <= 21, "R = {} is not in [1, 21]".format(R)
assert 1 <= C <= 21, "C = {} is not in [1, 21]".format(C)

grid = []
for r in range(R):
    line = stdin.readline()
    assert re.match('(#|\\.){{{}}}'.format(C) + "\n", line), \
        "Line must be consist of {} '#'s or '.'s. Got `{}`.".format(C, line)
    grid.append(line.strip())

line = stdin.readline()
assert re.match(integer + "\n", line), "N must be integer, got {}.".format(line)
N = int(line)
assert 1 <= N <= 200, "N = {} is not in [1, 200]".format(N)

for i in range(N):
    word = stdin.readline().rstrip("\n")
    assert word.isupper() and word.isalpha(), "Word `{}` must be uppercase letters".format(word)

assert len(sys.stdin.readline()) == 0, "Extra lines detected after input."

# Nothing to report.
sys.exit(42)
