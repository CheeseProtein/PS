import sys
A, B = map(int, sys.stdin.readline().split())
N, M = map(int, sys.stdin.readline().split())
loc = list()                                       # loc[robot] = [x, y]
direction = list()
DIR = {'N':0, 'W':1, 'S':2, 'E':3}
board = [[-1 for _ in range(A)] for _ in range(B)] # board[y][x]
dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]
result = ""

for n in range(N):
    x, y, d = sys.stdin.readline().split()
    loc.append([int(x)-1, int(y)-1])
    direction.append(DIR[d])
    board[int(y)-1][int(x)-1] = n

for _ in range(M):
    #print(board)

    rob, typ, rep = sys.stdin.readline().split()
    rob = int(rob) - 1
    rep = int(rep)

    if typ == "L":
        direction[rob] = (direction[rob] + (rep % 4)) % 4
    elif typ == "R":
        direction[rob] = (direction[rob] - (rep % 4)) % 4
    else:
        x = loc[rob][0]
        y = loc[rob][1]
        d = direction[rob]
        for r in range(rep):
            if result != "": break
            xx = x + dx[d]
            yy = y + dy[d]

            if not 0 <= xx < A or not 0 <= yy < B:
                result = f"Robot {rob+1} crashes into the wall"
            elif board[yy][xx] != -1:
                result = f"Robot {rob+1} crashes into robot {board[yy][xx]+1}"
            else:
                #print(f"rob#{rob+1}, xx = {xx} yy = {yy}.")
                #print(f"board[yy][xx] = {board[yy][xx]}, dir = {direction[rob]}")
                board[y][x] = -1
                board[yy][xx] = rob
                x = loc[rob][0] = xx
            y = loc[rob][1] = yy

if result != "": print(result)
else: print("OK")
