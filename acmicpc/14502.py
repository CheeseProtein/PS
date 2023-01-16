from collections import deque
import itertools
import copy

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

#남은 0의 개수
zeros = 0
for i in range(N): zeros += board[i].count(0)

#탐색 시작 위치 기록
vertice = [[i, j] for i in range (N) for j in range (M)]
starting = []
virus = []
for v in vertice:
    if board[v[0]][v[1]] == 2: virus.append([v[0], v[1]])
    elif board[v[0]][v[1]] == 0: starting.append([v[0], v[1]])

# 1
com = list(itertools.combinations(starting, 3))
move = ([-1,0],[0,-1],[0,1],[1,0])  # dr, dc
result = 0;
for wall in com:
    #print(f"wall at {wall[0], wall[1], wall[2]}")
    # 2
    boardcopy = copy.deepcopy(board)
    for i in wall:
        r_ = i[0]
        c_ = i[1]
        boardcopy[r_][c_] = 1

    count = zeros - 3
    q = copy.deepcopy(deque(virus))
    while len(q) > 0:
        v = q.popleft()
        #print(f"{v[0]}, {v[1]} is moving:")
        for d in range(4):
            rr = move[d][0] + v[0]
            cc = move[d][1] + v[1]
            #print(f"rr = {rr}, cc = {cc}")
            if rr >= 0 and rr < N and cc >= 0 and cc < M and boardcopy[rr][cc] == 0:
                #print(f"moved: appended [{rr}, {cc}]")
                count -= 1
                boardcopy[rr][cc] = 2
                q.append([rr, cc])
    result = count if result < count else result
    #print(f"count = {count} when wall = {wall}")
    #input()

print(result)
