N = 8

def is_print(board):
    for row in board:
        print(" ".join(str(x) for x in row))

def is_safe(row,col,slashcode,backslashcode,rowlookup,slashlookup,backslashlookup):
    if(rowlookup[row] or slashlookup[slashcode[row][col]] or backslashlookup[backslashcode[row][col]]):
        return False
    return True

def solve_util(board,col,slashcode,backslashcode,rowlookup,slashlookup,backslashlookup):
    if col >= N:
        return True

    for i in range(N):
        if(is_safe(i,col,slashcode,backslashcode,rowlookup,slashlookup,backslashlookup)):
            board[i][col] = 1
            rowlookup[i] = True
            slashlookup[slashcode[i][col]] = True
            backslashlookup[backslashcode[i][col]] = True

            if(solve_util(board,col+1,slashcode,backslashcode,rowlookup,slashlookup,backslashlookup)):
                return True

            board[i][col] = 0
            rowlookup[i] = False
            slashlookup[slashcode[i][col]] = False
            backslashlookup[backslashcode[i][col]] = False

    return False

def main():
    board = [[0]*N for _ in range(N)]
    slashcode = [[r+c for c in range(N)]for r in range(N)]
    backslashcode = [[r-c + (N-1) for c in range(N)]for r in range(N)]

    rowlookup = [False]*N
    slashlookup = [False]*(2*N-1)
    backslashlookup = [False]*(2*N-1)

    if(solve_util(board,0,slashcode,backslashcode,rowlookup,slashlookup,backslashlookup)):
        is_print(board)
    else:
        print("Solution doesn't exist")

main()