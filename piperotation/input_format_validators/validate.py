#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + " " + integer + "\n", line), \
    "'{}' is not a pair of integers".format(line)

R, C = map(int, line.split())
assert 1 <= R <= 2000, "R = {} is not in [1, 2000]".format(R)
assert 1 <= C <= 2000, "C = {} is not in [1, 2000]".format(C)

grid = []
for r in range(R):
    line = stdin.readline()
    assert re.match('[ABCD]{{{}}}'.format(C) + "\n", line), \
        "Line must be consist of {} chars from A-D. Got `{}`.".format(C, line)
    grid.append(line.strip())

assert len(sys.stdin.readline()) == 0, "Extra lines detected after input."

# Nothing to report.
sys.exit(42)
