#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C;
vector<int> cow;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> C;
	cow = vector<int>(N);
	for (auto &i : cow) cin >> i;
	sort(cow.begin(), cow.end());
	int lo = 0;
	int hi = cow[N-1] - cow[0];
	int answer = hi;
	while (lo <= hi) {
		int mid = (hi + lo) / 2;
		int m = 0, c = 1;
		int before = cow[0];
		for (int i = 1; i < N; ++i) {
			if (cow[i] - before > mid || c >= C) {
				// Next bus, increment m
				++m; c = 1;
				before = cow[i];
			} else {
				// current bus, increment c
				++c;
			}
		}
		++m;

		if (m > M) {  // fail, upper the time
			lo = mid + 1;
		} else {  // success, lower the time
			answer = mid;
			hi = mid - 1;
		}
	}
	cout << answer;
	return 0;
}