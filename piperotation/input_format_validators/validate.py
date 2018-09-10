#!/usr/bin/env python3
from sys import stdin
import re
import sys


line = stdin.readline()
try:
    R, C = map(int, line.strip().split())
except ValueError as e:
    assert(False)
assert(1 <= R <= 100 and 1 <= C <= 100)

# check for valid characters
grid = []
for r in range(R):
    line = stdin.readline().strip()
    if not line:
        assert(False)
    valid_chars = ['A', 'B', 'C', 'D'] 
    for c in range(C):
        if line[c] not in valid_chars:
            assert(False)
    grid.append(line)

# check for correct dimensions 
assert(len(grid) == R)
for line in grid:
    assert(len(line) == C)

sys.exit(42)