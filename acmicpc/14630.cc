/**
 * NPC week3: dijkstra
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>

#define todigit(c) (c - '0')
using namespace std;

int N;
int Now, Target;
vector<int> info[1001];

vector<int> di(int src) {
    vector<int> dist(N, 10000);
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;  // cost, vertex
    pq.emplace(0, src);
    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;

        for (int i = 0; i < N; ++i) {
            if (i == here) continue;
            int there = i;
            int nextDist = cost;
            for (size_t j = 0; j < info[here].size(); ++j) {
                nextDist += pow(info[here][j] - info[there][j], 2);
            }
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.emplace(-nextDist, there);
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string input; cin >> input;
        for (auto c : input) {
            info[i].push_back(todigit(c));
        }
    }
    // for (int i = 0; i < N; ++i) {
    //     cout << adj[i].front().first << " " << adj[i].front().second[0] << "\n";
    // }
    cin >> Now >> Target;
    auto result = di(Now - 1);
    // for (int i = 0; i < N; ++i) {
    //     cout << result[i] << "\n";
    // }
    cout << result[Target - 1];
    return 0;
}