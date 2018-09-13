#!/usr/bin/env python3
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + "\n", line), "'{}' is not an int".format(line)
N = int(line)
assert 1 <= N <= 200, "T = {} is not in [1, 200]".format(n, MAX)

vals = set()
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

assert len(vals) == N, "Values not a permutation of 1..{}".format(N)
assert cnt == N, "Number of lines ({}) not equal to N = {}".format(cnt, N)

# Nothing to report.
sys.exit(42)
