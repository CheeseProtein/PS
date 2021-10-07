/**
 * npc week3: Floyd-warshall
 */
#include <iostream>
#include <cstring>
using namespace std;

int INF = 999;
int N, M;
int adj[501][501];  

void Floyd() {
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}
}

int main() {
	memset(adj, 0, sizeof adj);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i != j) adj[i][j] = INF;
		}
	}
	for (int i = 0; i < M; ++i) {
		int small, tall;
		scanf("%d%d", &small, &tall);
		--small; --tall;
		adj[small][tall] = 1;
	}
	Floyd();
/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d ", adj[i][j]);
		}
		printf("\n");
	}
*/
	int result = 0;
	for (int i = 0; i < N; ++i) {
		int count = 0;
		for (int j = 0; j < N; ++j) {
			if (adj[i][j] < 999 || adj[j][i] < 999) ++count;
		}
		if (count == N) ++result;
	}
	printf("%d", result);	
	return 0;
}
