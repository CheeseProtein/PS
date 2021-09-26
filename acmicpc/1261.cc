#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int M, N;
int board[100][100];
bool visited[100][100];
deque<pair<int, pair<int, int>>> dq;  // cost, y, x
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main() {
  memset(board, -1, sizeof board);
  memset(visited, false, sizeof visited);
  scanf("%d%d", &M, &N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%1d", &board[i][j]);
    }
  }
  dq.push_front(make_pair(0, make_pair(0, 0)));
  visited[0][0] = true;
  while (!dq.empty()) {
    int cost = dq[0].first;
    int y = dq[0].second.first;
    int x = dq[0].second.second;
    dq.pop_front();

    if (x == M-1 && y == N-1) {
      printf("%d", cost);
      return 0;
    }

    for (int i = 0; i < 4; ++i) {
      int yy = y + dy[i];
      int xx = x + dx[i];
      if (0 <= xx && xx < M && 0 <= yy && yy < N && !visited[yy][xx]) {
        visited[yy][xx] = true;
        
        if (board[yy][xx] == 0) {
          dq.push_front(make_pair(cost, make_pair(yy, xx)));
        } else {
          dq.push_back(make_pair(cost + 1, make_pair(yy, xx)));
        }
      }
    }
  }
}
