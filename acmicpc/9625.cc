#include <iostream>
#include <vector>
using namespace std;

/**
 * Sa(n) = Sb(n-1)
 * Sb(n) = Sa(n-1) + Sb(n-1)
 * Sa(0) = 1, Sb(0) = 0
 */
vector<int> sa{1};
vector<int> sb{0};
int k;

void solve(int n) {
	int nextA = sb[n-1];
	int nextB = sa[n-1] + sb[n-1];
	sa.push_back(nextA);
	sb.push_back(nextB);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		solve(i);
	}
	cout << sa[k] << " " << sb[k];
	return 0;
}