from random import randint

def put_to_file(R, C, grid, path):
    """ Puts testcase to file in secret folder.
        R: int, number of rows in grid 
        C: int, number of columns in grid
        grid: list of str, 2d grid 
    """
    with open(path, 'a+') as open_file:
        open_file.seek(0, 0)
        open_file.write('{row} {col}\n'.format(row=R, col=C))
        for r in range(R):
            open_file.write('{}\n'.format(grid[r]))
        open_file.write('\n')

testcases = 10 
min_limit = 1
max_limit = 5 
pipes = ['A', 'B', 'C', 'D']

for t in range(6, testcases):
    R, C = randint(min_limit, max_limit), randint(min_limit, max_limit)
    grid = [['' for c in range(C)] for r in range(R)] 
    for r in range(R):
        for c in range(C):
            grid[r][c] = pipes[randint(1,4)-1]
        grid[r] = ''.join(grid[r])
    put_to_file(R, C, grid, 'secret/{testcase}.in'.format(testcase=str(t).zfill(2)))