// DFS
#include <bits/stdc++.h>
using namespace std;

int n, A[100001], visit = 1, start;
bool visited[100001];

void dfs(int here) {
	visited[here] = true;
	int sign[] = {1, -1};
	for (int i = 0; i < 2; ++i) {
		int there = here + sign[i] * A[here];
		if (!(0 < there && there <= n)) continue;
		if (visited[there]) continue;
		++visit;
		dfs(there);
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> A[i];
	}
	cin >> start;
	dfs(start);
	cout << visit;
}