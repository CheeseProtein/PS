#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[1000001];

int calc(int num, int depth) {
	if (num == 1) return depth;

	int results[3] = {1000000, 1000000, 1000000};
	if (num % 3 == 0) {
		if (cache[num/3] < 0) {
			cache[num/3] = calc(num/3, 1);
		}
	       	results[0] = cache[num/3] + depth;
	}
	if (num % 2 == 0) { 
		if (cache[num/2] < 0) {
			cache[num/2] = calc(num/2, 1);
		}
	       	results[1] = cache[num/2] + depth;
	}
	if (cache[num-1] < 0) {
		cache[num-1] = calc(num-1, 1);
	}
	results[2] = cache[num-1] + depth; 

	cache[num] = *min_element(results, results+3);
	return cache[num];
}

int main() {
	int N;
	memset(cache, -1, sizeof cache);
	scanf("%d", &N);
	printf("%d", calc(N, 0));
	return 0;
}
