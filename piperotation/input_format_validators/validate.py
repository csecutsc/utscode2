#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + " " + integer + "\n", line), \
    "'{}' is not a pair of integers".format(line)

N, M = map(int, line.split())
assert 1 <= N <= 100, "N = {} is not in [1, 100]".format(N)
assert 1 <= M <= 100, "M = {} is not in [1, 100]".format(M)

grid = []
for r in range(N):
    line = stdin.readline()
    assert re.match('[ABCD]{{{}}}'.format(M) + "\n", line), \
        "Line must be consist of {} chars from A-D. Got `{}`.".format(M, line)
    grid.append(line.strip())

assert len(sys.stdin.readline()) == 0, "Extra lines detected after input."

# Nothing to report.
sys.exit(42)
