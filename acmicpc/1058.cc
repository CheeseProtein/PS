#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N;
bool edges[50][50];
bool visited[50];  // 찾은 1-친구 기록
int Max = 0;

int main() {
  memset(edges, 0, sizeof edges);
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char ch;
      scanf(" %c", &ch);
      if (ch == 'Y') edges[i][j] = 1;
    }
  }
  // 각 사람에 대해 BFS하기
  for (int i = 0; i < N; ++i) {
    queue<int> q;
    int result = 0;
    memset(visited, 0, sizeof visited);

    for (int j = 0; j < N; ++j) {  // 1-친구 탐색
      if (edges[i][j]) {
        ++result;
        visited[j] = true;
        q.push(j);
      }
    }

    // 2-친구 탐색
    while (!q.empty()) {
      int one = q.front();
      q.pop();
      for (int two = 0; two < N; ++two) {
        if (two != i && !visited[two] && edges[one][two]) {
          ++result;
          visited[two] = true;
        }
      }
    }

    // 최대값 갱신
    Max = max(Max, result);
  }
  printf("%d", Max);
  return 0;
}
