#include <bits/stdc++.h>
using namespace std;

int n;
int tri[500][500];
int cache[500][500];

void dp(int row, int col) {
	if (!row) {
		cache[row][col] = tri[row][col];
		return;
	}
	// 현재 위치 row, col에서 최대값은
	// row-1, col-1 또는 row-1, row 중에 최대값 선택
	cache[row][col] = max(cache[row-1][col-1], cache[row-1][col]) + tri[row][col];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(tri, 0, sizeof tri);
	memset(cache, 0, sizeof cache);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			dp(i, j);
		}
	}
	int res = 0;
	for (int j = 0; j < n; ++j) {
		res = max(res, cache[n-1][j]);
	}
	cout << res;
	return 0;
}