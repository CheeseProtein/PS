#include <bits/stdc++.h>
using namespace std;

// 정점 수 == 간선 수, dense graph?? 인접 행렬
int students[100001];
int visited[100001];
int N;

int dfs(int first, int cur) {
		if (students[cur] == first)
				return visited[cur] = 1;
		else if (visited[students[cur]] != -1)
				return 0;
		else
				return visited[cur] = dfs(first, students[cur]);
}

int main() {
		ios::sync_with_stdio(false);
		cin.tie(0);
		int T; cin >> T;
		for (int t = 0; t < T; ++t) {
				memset(visited, -1, sizeof visited);
				cin >> N;
				for (int n = 1; n <= N; ++n) {
						int input; cin >> input;
						if (n == input) visited[n] = 1;
						students[n] = input;
				}
				for (int n = 1; n <= N; ++n) {
						if (visited[n] == -1) dfs(n, n);
				}
				for (int n = 1; n <= N; ++n) {
						int result = 0;
						if (!visited[n]) ++result;
						cout << result << "\n";
				}
		}
		return 0;
}
