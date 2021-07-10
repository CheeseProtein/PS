#include <iostream>
#include <cmath>

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	bool nprime[1000001] = { false };
	nprime[1] = true;
	
	int range = sqrt(N);
	for (int i = 2; i <= range; ++i) {
		if (nprime[i]) continue;
		for (int j = 2; j * i <= N; ++j) {
			nprime[j * i] = true;
		}
	}

	for (int i = M; i <= N; ++i) {
		if (!nprime[i]) {
			printf("%d\n", i);
		}
	}

	return 0;
}
