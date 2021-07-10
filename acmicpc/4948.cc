#include <iostream>
#include <cmath>

int main() {
	int range = sqrt(123456*2);
	bool nprime[123456*2] = { false };
	nprime[1] = true;
	for (int i = 2; i <= range; ++i) {
		if (nprime[i]) continue;
		for (int j = 2; j * i <= 123456*2; ++j) {
			nprime[j * i] = true;
		}		
	}

	while (true) {
		int n;
		scanf("%d", &n);
		if (!n) return 0;

		int count = 0;
		for (int i = n+1; i <= 2*n; ++i) {
			if (!nprime[i])
				++count;
		}
		printf("%d\n", count);
	}
}
