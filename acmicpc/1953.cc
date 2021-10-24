#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> team[2];
vector<vector<int>> adj;
vector<bool> discovered;

void dfs(int src, int where) {
	discovered[src] = true;
	team[where].push_back(src);
	for (size_t i = 0; i < adj[src].size(); ++i) {
		int there = adj[src][i];
		if (!discovered[there]) {
			dfs(there, (where + 1) % 2);
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		vector<int> list;
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; ++j) {
			int item;
			scanf("%d", &item);
			list.push_back(item - 1);
		}
		adj.push_back(list);
	}

	discovered = vector<bool>(N, false);
	for (int i = 0; i < N; ++i) {
		if (!discovered[i]) dfs(i, i % 2);
	}

	for (int i = 0; i < 2; ++i) {
		sort(team[i].begin(), team[i].end());
		printf("%ld\n", team[i].size());
		for (size_t j = 0; j < team[i].size(); ++j) {
			printf("%d ", team[i][j] + 1);
		}
		printf("\n");
	}
	return 0;
}
