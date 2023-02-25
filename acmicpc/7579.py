import sys
N, M = map(int, sys.stdin.readline().split())
Value = list(map(int, sys.stdin.readline().split()))
Cost = list(map(int, sys.stdin.readline().split()))
Memo = [[0 for _ in range(10001)] for _ in range(N+1)]  # Memo[n][cost] = values to get

for n in range(1, N+1):
    for c in range(10001):
        if Cost[n-1] <= c:
            Memo[n][c] = max(Memo[n-1][c], Memo[n-1][c-Cost[n-1]] + Value[n-1])
        else:
            Memo[n][c] = Memo[n-1][c]

res = 0
for i in range(10001):
    if Memo[N][i] >= M:
        res = i
        break

#print(Memo[1][:20])
#print(Memo[2][:20])
#print(Memo[3][:20])
#print(Memo[4][:20])
#print(Memo[5][:20])
print(res)
