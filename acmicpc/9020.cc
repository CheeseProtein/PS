#include <iostream>

int main() {
	int T;
	scanf("%d", &T);

	bool nprime[10001] = { false };
	nprime[1] = true;

	for (int i = 2; i * i <= 10000; ++i) {
		if (nprime[i]) continue;
		for (int j = 2; j * i <= 10000; ++j) {
			nprime[j * i] = true;
		}
	}

	for (int i = 0; i < T; ++i) {
		int n;
		scanf("%d", &n);

		int j;
		for (j = (n / 2); ; --j) {
			if (!nprime[j] && !nprime[n - j]) {
				break;		
			}
		}
		printf("%d %d\n", j, n - j);
	}
	return 0;
}
