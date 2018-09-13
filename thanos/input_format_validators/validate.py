#!/usr/bin/env python3
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + "\n", line), "'{}' is not an int".format(line)
T = int(line)
assert 1 <= T <= 10000, "T = {} is not in [1, 10000]".format(n, MAX)

cases = 0
while True:
    line = sys.stdin.readline()
    if len(line) == 0:
        break
    assert re.match(integer + " " + integer + " " + integer + "\n", line), \
        "'{}' is not a triplet of ints".format(line)
    P, R, F = map(int, line.strip().split())
    assert 1 <= P <= 10**9, "{} is not in [1, 10^9]".format(P)
    assert 1 <= R <= 500, "{} is not in [1, 500]".format(R)
    assert 1 <= F <= 10**9, "{} is not in [1, 10^9]".format(F)
    cases += 1

assert cases == T, "number of cases ({}) not equal to T ({})".format(cases, T)

# Nothing to report.
sys.exit(42)
