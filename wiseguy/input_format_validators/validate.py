#!/usr/bin/env python3
import re
import sys

integer = "(0|-?[1-9]\\d*)"
MAX = 500

line = sys.stdin.readline()
assert re.match(integer + "\n", line), "'{}' is not an int".format(line)
T = int(line)
assert 1 <= T <= 500, "T = {} is not in [1, 500]".format(n, MAX)

cases = 0
while True:
    line = sys.stdin.readline()
    if len(line) == 0:
        break
    assert re.match(integer + "\n", line), "'{}' is not an int".format(line)
    N = int(line)
    assert 1 <= N <= MAX, "{} is not in [0, {}]".format(n, MAX)
    cases += 1

assert cases == T, "number of cases ({}) not equal to T ({})".format(cases, T)

# Nothing to report.
sys.exit(42)
