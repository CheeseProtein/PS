#include <iostream>
#include <cstring>
using namespace std;

int board[51][51];
int visited[51][51];
int M, N, K, X, Y;
int count;

void dfs(int x, int y) {
	visited[x][y] = 1;
	// visit the right node
	if (x < M && board[x+1][y] && !visited[x+1][y]) {
		dfs(x+1, y);
	}
	// visit the lower node
	if (y < N && board[x][y+1] && !visited[x][y+1]) {
		dfs(x, y+1);
	}
	// visit the left lode
	if (x > 0 && board[x-1][y] && !visited[x-1][y]) {
		dfs(x-1, y);
	}
	// visit the upper lode
	if (y > 0 && board[x][y-1] && !visited[x][y-1]) {
		dfs(x, y-1);
	}
}

void dfsAll() {
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (board[x][y] && !visited[x][y]) {
				++count;
				dfs(x, y);
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d%d%d", &M, &N, &K);
		memset(board, 0, sizeof board);
		memset(visited, 0, sizeof visited);
		for (int j = 0; j < K; ++j) {
			scanf("%d%d", &X, &Y);
			board[X][Y] = 1;
		}
		count = 0;
		dfsAll();
		printf("%d\n", count);
	}	
	return 0;
}
