#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, V;
int edge[1001][1001];
int visited[1001];
queue<int> q;

void dfs(int vertex) {
	visited[vertex] = 1;
	printf("%d ", vertex);
	for (int i = 1; i < 1001; ++i) {
		if (edge[vertex][i] && !visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	memset(edge, 0, sizeof edge);	
	memset(visited, 0, sizeof visited);
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0; i < M; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x][y] = edge[y][x] = 1;
	}
	dfs(V);
	printf("\n");
	memset(visited, 0, sizeof visited);
	q.push(V);
	visited[V] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (int i = 1; i < 1001; ++i) {
			if (edge[cur][i] && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	return 0;
}
