#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
single_integer = re.compile(integer + '\n')
two_int_first_line = re.compile(integer + " " + integer + "\n")

line = stdin.readline()
assert single_integer.match(line)

for _ in range(int(line)):
    n_line = stdin.readline()
    assert two_int_first_line.match(n_line)
    r, d = map(int, n_line.split())
    assert 1 <= r <= 10**9 and 1 <= d <= 10**9

sys.exit(42)
