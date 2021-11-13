#include <iostream>
#include <cstring>
using namespace std;

int N, a, b;
int cache[1000001];

int go(int n) {
	if (!n) return 0;
	if (n == 1) return 1;
	if (n == a + 1 || n == b + 1) return 1;

	int &ret = cache[n];
	if (ret != -1) return ret;
	int skip = 1000001;
	if (n - 1 >= a) skip = min(1 + go(n-a-1), skip);
	if (n - 1 >= b) skip = min(1 + go(n-b-1), skip);
	return ret = min(1 + go(n-1), skip);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> a >> b;
	memset(cache, -1, sizeof cache);
	cout << go(N);
	return 0;
}