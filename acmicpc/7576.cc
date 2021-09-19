#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int M, N;
// int board[1000][1000];
bool visited[1000][1000];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int zeros = 0;
int recent_dist = 0;

int main() {
  // memset(board, -1, sizeof board);
  memset(visited, true, sizeof visited);
  scanf("%d%d", &M, &N);

  queue<pair<int, pair<int, int>>> q;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      int in;
      scanf("%d", &in);
      if (in == 1) { q.push(make_pair(0, make_pair(i, j))); }
      else if (!in) { ++zeros; visited[i][j] = false; }
    }
  }

  while (!q.empty()) {
    int y = q.front().second.first;
    int x = q.front().second.second;
    int dist = q.front().first;
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (0 <= xx && xx < M && 0 <= yy && yy < N && !visited[yy][xx]) {
        visited[yy][xx] = true;
        --zeros;
        recent_dist = dist + 1;
        q.push(make_pair(dist + 1, make_pair(yy, xx)));
      }
    }
  }

  if (zeros) {
    printf("-1");
  } else {
    printf("%d", recent_dist);
  }
  return 0;
}
