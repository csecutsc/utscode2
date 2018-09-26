from collections import deque

R, C = map(int, raw_input().split())
G = [list(raw_input().strip()) for _ in xrange(R)]

total = 0
components = 0

# Initialize pointers.
lcol = [[-1 for c in xrange(C)] for r in xrange(R)]
rcol = [[-1 for c in xrange(C)] for r in xrange(R)]
urow = [[-1 for c in xrange(C)] for r in xrange(R)]
drow = [[-1 for c in xrange(C)] for r in xrange(R)]

for i in xrange(R):
    curr = -1
    for j in xrange(C):
        if G[i][j] == 'x':
            lcol[i][j] = curr
            curr = j
    curr = -1
    for j in xrange(C - 1, -1, -1):
        if G[i][j] == 'x':
            rcol[i][j] = curr
            curr = j

for j in xrange(C):
    curr = -1
    for i in xrange(R):
        if G[i][j] == 'x':
            urow[i][j] = curr
            curr = i
    curr = -1
    for i in xrange(R - 1, -1, -1):
        if G[i][j] == 'x':
            drow[i][j] = curr
            curr = i


def update_pointers(r, c):
    if lcol[r][c] != -1:
        if rcol[r][c] != -1:
            rcol[r][lcol[r][c]] = rcol[r][c]
            lcol[r][rcol[r][c]] = lcol[r][c]
        else:
            rcol[r][lcol[r][c]] = -1

    if urow[r][c] != -1:
        if drow[r][c] != -1:
            drow[urow[r][c]][c] = drow[r][c]
            urow[drow[r][c]][c] = urow[r][c]
        else:
            drow[urow[r][c]][c] = -1

    if rcol[r][c] != -1:
        if lcol[r][c] != -1:
            lcol[r][rcol[r][c]] = lcol[r][c]
            rcol[r][lcol[r][c]] = rcol[r][c]
        else:
            lcol[r][rcol[r][c]] = -1

    if drow[r][c] != -1:
        if urow[r][c] != -1:
            urow[drow[r][c]][c] = urow[r][c]
            drow[urow[r][c]][c] = drow[r][c]
        else:
            urow[drow[r][c]][c] = -1


q = deque()

def try_append(r, c):
    if r != -1 and c != -1 and G[r][c] == 'x':
        q.append((r, c))
        G[r][c] = '.'

for i in xrange(R):
    for j in xrange(C):
        if G[i][j] == 'x':
            components += 1
            q = deque()
            q.append((i, j))
            while q:
                r, c = q.popleft()
                total += 1
                update_pointers(r, c)
                try_append(r, lcol[r][c])
                try_append(urow[r][c], c)
                try_append(r, rcol[r][c])
                try_append(drow[r][c], c)

print total - components
