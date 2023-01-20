import sys
import heapq
import copy

N, M, X = map(int, sys.stdin.readline().split())
edge = [[987654321 for i in range(N)] for j in range(N)]

for m in range(M):
    here, there, cost = map(int, sys.stdin.readline().split())
    edge[here-1][there-1] = cost

def dijkstra(start, reverse):
    global N, edge
    dist = [987654321 if i != start else 0 for i in range(N)]
    q = []
    for i in range(N):
        q.append([edge[start][i], i] if not reverse else [edge[i][start], i])
        if i != start: dist[i] = edge[start][i] if not reverse else edge[i][start]
    heapq.heapify(q)

    while q:
        qq = heapq.heappop(q)
        cost = qq[0]
        here = qq[1]

        if dist[here] < cost: continue

        for i in range(N):
            thereCost = edge[here][i] if not reverse else edge[i][here]
            if dist[i] > cost + thereCost:
                dist[i] = cost + thereCost
                heapq.heappush(q, [cost + thereCost, i])

    return dist

arrive = dijkstra(X-1, True)
depart = dijkstra(X-1, False)
maxima = 0
for i in range(N):
    maxima = arrive[i] + depart[i] if maxima < arrive[i] + depart[i] else maxima
print(maxima)
