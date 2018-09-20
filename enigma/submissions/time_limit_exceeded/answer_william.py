#!/usr/bin/python3

# variables used in bactracking recursion, stored in parent 
# scope for recursion efficency
LIMIT = 21
words = []
wlen = []
lenH = [[0 for j in range(LIMIT) ] for i in range(LIMIT)]
lenV = [[0 for j in range(LIMIT) ] for i in range(LIMIT)]
usedH = [[False for j in range(LIMIT) ] for i in range(LIMIT)]
usedV = [[False for j in range(LIMIT) ] for i in range(LIMIT)]
recFurther = True 

def solve(R, C, grid, N, given_words):
    """
    Args:
        R: int, number of rows in grid.
        C: int, number of cols in grid.
        grid: 2d list of characters, 
        N: int, number of words
        words: list of str, words to place in the puzzle.
    Returns: 
        list of str, with words place, otherwise returns the original grid.
    """
    global wlen, lenH, lenV , words
    # Sort the words by length.
    words = sorted(given_words, key=lambda word: len(word), reverse=True)
    wlen = list(map(lambda word: len(word), words))
    # Precompute horizontal grid lengths.
    for i in range(R):
        j = 0
        while j < C:
            if grid[i][j] == '.':
                k = j+1
                while k < C and grid[i][k] == '.':
                    k = k+1
                lenH[i][j] = k-j;
                j = k
            j = j+1
    # Precompute vertical grid lengths
    for i in range(C):
        j = 0
        while j < R:
            if grid[j][i] == '.':
                k = j+1
                while k < R and grid[k][i] == '.':
                    k = k+1
                lenV[j][i] = k-j;
                j = k
            j = j+1
    def rec(i):
        """Backtracking recursive algorithm.
        Args:
            i: int, current index of word in list to place 
        Returns:
            str, delimited by '\n'
        """
        global wlen
        global lenH
        global lenV
        global usedH
        global usedV
        global recFurther
        global words
        # global check for recursion
        if recFurther:
            if i == N:
                ans = [''.join(i) for i in grid] 
                ans = '\n'.join(ans)
                recFurther = False
                print(ans)
                exit(0)
                return ans
            # place next word horizontally
            for r in range(R):
                c = 0
                while c + wlen[i] - 1 < C:
                    if lenH[r][c] == wlen[i] and not usedH[r][c]: 
                        # check for validity 
                        space_len =  0
                        for j in range(wlen[i]):
                            if grid[r][c+j] != '.' and grid[r][c+j] != words[i][j]:
                                break
                            space_len = j+1
                        # attempt to place the word
                        if space_len == wlen[i]:
                            col_changed = [False for i in range(wlen[i])]
                            for j in range(wlen[i]):
                                if grid[r][c+j] == '.':
                                    # replace index
                                    grid[r][c+j] = words[i][j]
                                    col_changed[j] = True
                            usedH[r][c] = True
                            # recurse after placing word
                            if recFurther:
                                ret = rec(i+1)
                                if ret:
                                    return ret 

                            usedH[r][c] = False
                            for j in range(wlen[i]):
                                if col_changed[j]:
                                    grid[r][c+j] = '.'
                    c = c+1
                # place next word vertically
                r = 0
                while r + wlen[i] -1 < R:
                    for c in range(C):
                        if lenV[r][c] == wlen[i] and not usedV[r][c]:
                            # check valididty
                            space_len = 0 
                            for j in range(wlen[i]):
                                if grid[r+j][c] != '.' and grid[r+j][c] != words[i][j]:
                                    break
                                space_len = j+1
                            if space_len == wlen[i]:
                                # place word
                                col_changed = [False for i in range(wlen[i])]
                                for j in range(wlen[i]):
                                    if grid[r+j][c] == '.':
                                        # replace index
                                        grid[r + j][c] = words[i][j]; 
                                        col_changed[j] = True
                                usedV[r][c] = True
                                if recFurther:
                                    ret = rec(i+1)
                                    if ret:
                                        return ret 
                                usedV[r][c] = False
                                for j in range(wlen[i]):
                                    if col_changed[j]:
                                        grid[r+j][c] = '.'
                    r = r+1
    return rec(0)





if __name__ == '__main__':
    R, C = map(int, input().strip().split())
    grid = []
    for i in range(R):
        line = input().strip()
        grid.append(list(line))
    N = int(input())
    words = []
    for i in range(N):
        line = input().strip()
        words.append(line)
    print(solve(R, C, grid, N, words))
