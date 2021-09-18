#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int board[50][50];
int visited[50][50];
int MaxResult = 0;

int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &board[i][j]);
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (!board[i][j]) {  // 각 칸에 상어 없으면 확인
        int curResult = 1;
        memset(visited, 0, sizeof visited);
        visited[i][j] = 1;

        queue<pair<int, pair<int, int>>> q;
        q.push(make_pair(1, make_pair(i, j)));

        while (!q.empty()) {
          bool foundShark = false;
          int dist = q.front().first;
          int y = q.front().second.first;
          int x = q.front().second.second;
          q.pop();

          for (int k = 0; k < 8; ++k) {  // 다음 위치 확인
            int yy = y + dy[k];
            int xx = x + dx[k];
            if (0 <= yy && yy < N && 0 <= xx && xx < M && !visited[yy][xx]) {  // 다음 위치가 갈 수 있는 곳일 때
              if (board[yy][xx]) {  // 상어 있으면 현재 위치 기록하고 중단
                foundShark = true;
                curResult = dist;
                break;
              } else {  // 상어 없으면 다음 위치 큐에 삽입
                visited[yy][xx] = 1;
                q.push(make_pair(dist + 1, make_pair(yy, xx)));
              }
            }
          }

          if (foundShark) break;
          else curResult = dist;
        }

        // 각 유효 칸 탐색 종료마다 최대값이면 갱신
        MaxResult = max(curResult, MaxResult);
      }
    }
  }

  printf("%d", MaxResult);
  return 0;
}
