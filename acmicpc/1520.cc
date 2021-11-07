#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;
int M, N;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int run(int x, int y) {
  if (x == N-1 && y == M-1) return 1;

  if (visited[y][x] == -1) {

    visited[y][x] = 0;
    for (int i = 0; i < 4; ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
    if (0 <= xx && xx < N && 0 <= yy && yy < M && board[y][x] > board[yy][xx]) {
        visited[y][x] += run(xx, yy);
      }
    }

  }
  return visited[y][x];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> M >> N;

  board = visited = vector<vector<int>>(M, vector<int>(N, -1));
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> board[i][j];
    }
  }

  cout << run(0, 0);
  return 0;
}
