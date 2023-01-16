N = int(input())
board = [list(map(int, input().split())) for i in range(N)]

def dp(row, col, direction):
    #print(f"row = {row}, col = {col}, dir = {direction}")
    global N
    if row == N-1 and col == N-1: return 1
    ret = 0
    if direction == 0 and col+1 < N and not board[row][col+1]:
        ret += dp(row, col+1, 0)
        if row+1 < N and not board[row+1][col] and not board[row+1][col+1]: ret += dp(row+1, col+1, 2)
    if direction == 1 and row+1 < N and not board[row+1][col]:
        ret += dp(row+1, col, 1)
        if col+1 < N and not board[row][col+1] and not board[row+1][col+1]: ret += dp(row+1, col+1, 2)
    if direction == 2:
        if col+1 < N and not board[row][col+1]: 
            ret += dp(row, col+1, 0)
        if row+1 < N and not board[row+1][col]:
            ret += dp(row+1, col, 1)
        if row+1 < N and col+1 < N and not board[row][col+1] and not board[row+1][col] and not board[row+1][col+1]:
            ret += dp(row+1, col+1, 2)
    return ret

print(dp(0,1,0))
