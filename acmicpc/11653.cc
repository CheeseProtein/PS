#include <iostream>
#include <cmath>
#include <cstring>

int main() {
	int N;
	scanf("%d", &N);

	if (N == 1) return 0;
	
	bool *nprime = new bool[10000001];
	memset(nprime, false, sizeof(bool) * 10000001);
	nprime[1] = true;
	
	int range = sqrt(N);
	for (int i = 2; i <= range; ++i) {
		if (nprime[i]) continue;
		for (int j = 2; j * i <= N; ++j) {
			nprime[j * i] = true;
		}
	}

	int cur_prime = 2;
	while (N > 1) {
		if (N % cur_prime == 0) {
			printf("%d\n", cur_prime);
			N /= cur_prime;
			continue;
		}
		while (nprime[++cur_prime]);
	}

	delete[] nprime;
	return 0;
}
