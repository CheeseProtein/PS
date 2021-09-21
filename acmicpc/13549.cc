#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, K;

vector<int> di() {
        vector<int> dist(100001, 100002);
        dist[N] = 0;

        priority_queue<pair<int, int>> pq;  // time, location
        pq.emplace(0, N);

        while (!pq.empty()) {
                int time = -pq.top().first;
                int here = pq.top().second;
                pq.pop();

                if (dist[here] < time) continue;

                if (here) {
                                int there = here * 2;
                                if (there <= 100000 && dist[there] > time) {
                                        dist[there] = time;
                                        pq.emplace(-time, there);
                                }
                }

                if (here > 0) {
                        int there = here - 1;
                        if (dist[there] > time + 1) {
                                dist[there] = time + 1;
                                pq.emplace(-(time+1), there);
                        }
                }

                if (here < 100000) {
                        int there = here + 1;
                        if (dist[there] > time + 1) {
                                dist[there] = time + 1;
                                pq.emplace(-(time+1), there);
                        }
                }
        }
        return dist;
}

int main() {
        scanf("%d%d", &N, &K);
        auto temp = di();
        printf("%d", temp[K]);
        return 0;
}
