#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> house;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int n = 0; n < N; ++n) {
		int input;
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());
	int lo = 1;
	int hi = house[N-1] - house[0];
	int answer = hi;
	while (lo <= hi) {  // *** <=
		int mid = (hi + lo) / 2;  // current dist
		int cnt = 1;
		int last = house[0];
		for (int i = 1; i < N; ++i) {
			if (house[i] - last >= mid) {
				++cnt;
				last = house[i];
			}
		}
		if (cnt < C) {  // lower the distance
			hi = mid - 1;  // *** -1
		} else {  // might be answer, upper the distance
			answer = lo = mid;
			++lo;  // *** +1
		}
	}
	cout << answer;
	return 0;
}