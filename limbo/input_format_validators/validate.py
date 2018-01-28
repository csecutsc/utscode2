#!/usr/bin/env python3
from sys import stdin
import re
import sys

integer = "(0|-?[1-9]\d*)"
two_int_first_line = re.compile(integer + " " + integer + "\n")

line = stdin.readline()
assert two_int_first_line.match(line)
r, d = map(int, line.split())
assert 0 <= r <= 2**31-1 and 0 <= d <= 2**31-1

sys.exit(42)
