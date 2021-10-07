/**
 * NPC week3: dijkstra
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<vector<int>> arr;

int dy[] = { 1, 0 };
int dx[] = { 0, 1 };

vector<vector<int>> di() {
    vector<vector<int>> dist(N, vector<int>(N, 0x7fffffff));
    dist[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;  // cost, (row, col)
    pq.emplace(0, make_pair(0, 0));

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int hereR = pq.top().second.first;
        int hereC = pq.top().second.second;
        pq.pop();

        if (dist[hereR][hereC] < cost) continue;

        for (int i = 0; i < 2; ++i) {
            int thereR = hereR + dy[i];
            int thereC = hereC + dx[i];

            if (!(thereR < N && thereC < N)) continue;
            int nextDist = arr[hereR][hereC] > arr[thereR][thereC] ? cost : (arr[thereR][thereC] - arr[hereR][hereC] + 1 + cost);

            if (dist[thereR][thereC] > nextDist) {
                dist[thereR][thereC] = nextDist;
                pq.emplace(-nextDist, make_pair(thereR, thereC));
            }
        }
    }

    return dist;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        vector<int> temp;
        for (int j = 0; j < N; ++j) {
            int num;
            scanf("%d", &num);
            temp.push_back(num);
        }
        arr.push_back(temp);
    }

    auto temp = di();
    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < N; ++j) {
    //         printf("%d ", temp[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", temp[N-1][N-1]);
    return 0;
}