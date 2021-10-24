// topological sort
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> finished;

void dfs(int here) {
	visited[here] = true;
	for (size_t i = 0; i < adj[here].size(); ++i) {
		int there = adj[here][i];
		if (!visited[there]) {
			dfs(there);
		}
	}
	finished.push_back(here);
}

void dfsAll() {
	visited = vector<bool>(N, false);
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	adj = vector<vector<int>>(N, vector<int>());
	for (int i = 0; i < M; ++i) {
		int small, tall;
		cin >> small >> tall;
		adj[small - 1].push_back(tall - 1);
	}

	dfsAll();
	for (size_t i = 0; i < finished.size(); ++i) {
		cout << finished[finished.size() - 1 - i] + 1 << " ";
	}
	return 0;
}
