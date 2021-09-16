#include <iostream>
#include <cstring>
using namespace std;

int n;
int forest[501][501];
// int visited[501][501];
int result[501][501];
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};
int Max = 0;

int dfs(int x, int y) {
        // visited[y][x] = 1;
        if (result[y][x])
                return result[y][x];

        result[y][x] = 1;
        for (int i = 0; i < 4; ++i) {
                if (0 <= y + dy[i] && y + dy[i] < n &&
                    0 <= x + dx[i] && x + dx[i] < n &&
                    /*!visited[y+dy[i]][x+dx[i]] && */
                    forest[y + dy[i]][x + dx[i]] > forest[y][x]) {
                        result[y][x] = max(result[y][x], dfs(x+dx[i], y+dy[i]) + 1);
                }
        }
        return result[y][x];
}

void dfsAll() {
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        Max = max(Max, dfs(i, j));
                }
        }
}

int main() {
        memset(forest, 0, sizeof forest);
        memset(result, 0, sizeof result);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        scanf("%d", &forest[i][j]);
                }
        }
        dfsAll();
        /*
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        printf("%d ", result[i][j]);
                }
                printf("\n");
        }
        */
        printf("%d", Max);
        return 0;
}
