#include <bits/stdc++.h>
using namespace std;

int row;
int cost[1000][3];
int cache[1000][3];

// 현재 row에서 색상을 choice로 선택할 때, 최소 cost
int dp(int hereRow, int choice) {
	// 첫 row이면, 바로 cost 반환
	if (hereRow == 0) return cost[hereRow][choice];

	// 이전 row에서 다른 색상을 골랐을 때, 최소 cost를 구함
	int &ret = cache[hereRow][choice];
	ret = min(cache[hereRow-1][(choice+1)%3], cache[hereRow-1][(choice+2)%3]);
	// 현재 row의 cost를 더함
	ret += cost[hereRow][choice];
	// 반환
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin >> row;
	for (int i = 0; i < row; ++i) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	for (int i = 0; i < row; i++) {
		cache[i][0] = dp(i, 0);
		cache[i][1] = dp(i, 1);
		cache[i][2] = dp(i, 2);
	}
	int res = min(min(cache[row-1][0], cache[row-1][1]), cache[row-1][2]);
	cout << res;
	return 0;
}
