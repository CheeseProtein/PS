#include <bits/stdc++.h>
using namespace std;

// 반례
// 1
// 5
// 2 3 4 5 4

int students[100001];
int visited[100001];
int N;

int dfs(int first, int cur) {
		if (students[cur] == first)
				return visited[cur] = 1;
		else if (visited[students[cur]] != -1)
				return visited[cur] = 0;
		else
				return visited[cur] = dfs(first, students[cur]);
}

int main() {
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
				int result = 0;
				for (int n = 1; n <= N; ++n) {

						if (!visited[n]) ++result;
				}
				cout << result << "\n";
		}
		return 0;
}
