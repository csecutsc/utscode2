#!/usr/bin/env python3
import re
import sys

integer = "(0|-?[1-9]\\d*)"

line = sys.stdin.readline()
assert re.match(integer + " " + integer + "\n", line), "'{}' is not a pair of integers".format(line)

R, C = map(int, line.split())
assert 1 <= R <= 4, "R = {} is not in [1, 4]".format(R)
assert 1 <= C <= 4, "C = {} is not in [1, 4]".format(C)

assert len(sys.stdin.readline()) == 0, "Extra values detected after line."

# Nothing to report.
sys.exit(42)
