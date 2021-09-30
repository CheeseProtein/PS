/**
 * Solve a BFS prob
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, K;
queue<pair<int, int>> Q;  // location, time
bool visited[100001];

int main() {
  memset(visited, false, sizeof visited);
  scanf("%d%d", &N, &K);
  Q.push(make_pair(N, 0));
  while (!Q.empty()) {
    int here = Q.front().first;
    int time = Q.front().second;
    Q.pop();
    visited[here] = true;

    if (here == K) {
      printf("%d", time);
      return 0;
    }

    if (here > 0 && !visited[here - 1]) {
      Q.push(make_pair(here - 1, time + 1));
    }
    if (here < 100000 && !visited[here + 1]) {
      Q.push(make_pair(here + 1, time + 1));
    }
    if (here && here < 50001 && !visited[here * 2]) {
      Q.push(make_pair(here * 2, time + 1));
    }
  }
}
