/**
 * Solve a BFS prob with NPC (week 2)
 */
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> adj[200000];
queue<int> q;  // person
int visited[200000];

int main() {
    memset(visited, -1, sizeof visited);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        while (true) {
            int num;
            scanf("%d", &num);
            if (!num) break;
            adj[i].push_back(num - 1);
        }
    }
    scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int num;
        scanf("%d", &num);
        q.push(num - 1);
        visited[num - 1] = 0;
    }

    // 새로운 믿는 사람이 생길 때마다 반복
    while (!q.empty()) {
        // 새로운 믿는 사람의 번호
        int here = q.front();
        // 현재 퍼뜨리는 사람이 믿기 시작한 시간
        int time = visited[here];
        q.pop();

        for (size_t i = 0; i < adj[here].size(); ++i) {
            // 주변인의 번호
            int there = adj[here][i];

            // 믿지 않는 주변인이 있으면 루머 퍼뜨리기
            if (visited[there] == -1) {
                // 그 주변인의 커트라인
                int cutline = adj[there].size() % 2 ? adj[there].size() / 2 + 1 : adj[there].size() / 2 ;
                // 그 주변인 근처의 믿는 사람 수
                int believers = 0;
                // 믿는 사람 중 가장 마지막에 믿은 사람의 시간
                int latest_time = 0;
                for (size_t i = 0; i < adj[there].size(); ++i) {
                    // 커트라인을 넘는지 확인하기
                    if (-1 < visited[adj[there][i]] && visited[adj[there][i]] <= time) {
                        ++believers;
                        latest_time = max(latest_time, visited[adj[there][i]]);
                    }
                }
                // 커트라인을 넘었다면, 주변인도 이제 믿기 시작함
                if (believers >= cutline) {
                    visited[there] = latest_time + 1;
                    q.push(there);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ", visited[i]);
    }
    return 0;
}
