#include <bits/stdc++.h>
using namespace std;

int students[100001];  // adjecent list
vector<pair<int, int>> visited;  // first searched node, depth
int N;
int Result;

void dfs(int first, int cur, int depth) {
	visited[cur] = {first, depth};

	int next = students[cur];
	if (visited[next].first) {
		if (first != visited[next].first) return;
		int cycle = visited[next].second;
		Result += (depth - cycle + 1);
		return;
	}

	if (!visited[next].first)
		dfs(first, next, depth + 1);
}

int main() {
		int T; cin >> T;
		for (int t = 0; t < T; ++t) {
				cin >> N;
				Result = 0;
				visited = vector<pair<int, int>>(N + 1, {0, 0});
				for (int n = 1; n <= N; ++n) {
						int input; cin >> input;
						students[n] = input;
						if (input == n) {
							Result++;
							visited[n] = {n, 1};
						}
				}
				for (int n = 1; n <= N; ++n) {
					if (!visited[n].first) dfs(n, n, 1);
				}
				cout << N - Result << "\n";
		}
		return 0;
}
