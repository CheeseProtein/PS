/**
 * NPC week3: Dijkstra
 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int A, B, C;
vector<pair<int, int>> adj[100001];  // length, end for each start

vector<int> di(int src) {
    vector<int> dist(N + 1, 0x7fffffff);
    dist[src] = 0;

    priority_queue<pair<int, int>> pq;  // -length, end
    pq.emplace(0, src);

    while (!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < adj[here].size(); ++i) {
            int there = adj[here][i].second;
            int nextDist = adj[here][i].first + cost;
            if (nextDist < dist[there]) {
                dist[there] = nextDist;
                pq.emplace(-nextDist, there);
            }
        }
    }

    return dist;
}

int main() {
    scanf("%d%d%d%d%d", &N, &A, &B, &C, &M);
    for (int i = 0; i < M; ++i) {
        int start, end, len;
        scanf("%d%d%d", &start, &end, &len);
        adj[start].push_back(make_pair(len, end));
        adj[end].push_back(make_pair(len, start));
    }
    int maxplace, maxdist = 0;
    auto resultA = di(A);
    auto resultB = di(B);
    auto resultC = di(C);
    vector<int> result(N + 1, 0x7fffffff);
    int total_max = 0, total_max_place;
    for (int i = 1; i <= N; ++i) {
        if (i == A || i == B || i == C) continue;
        result[i] = min(resultA[i], resultB[i]);
        result[i] = min(result[i], resultC[i]);

        if (total_max < result[i]) {
            total_max = result[i];
            total_max_place = i;
        }
    }
    printf("%d", total_max_place);

    return 0;
}
