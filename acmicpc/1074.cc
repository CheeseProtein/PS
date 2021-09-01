#include <iostream>
#include <cmath>

int main() {
	int count = 0;
	int x = 0;
	int y = 0;
	int N, r, c;
	scanf("%d%d%d", &N, &r, &c);	
	int len = exp2(N);
	int dcount = exp2(2*(N-1));
	for (int n = 1; n <= N; ++n) {
		if (!(y <= r && r < y + len / 2)) {
			y += len / 2;
			count += dcount * 2;
		}
		if (!(x <= c && c < x + len / 2)) {
			x += len / 2;
			count += dcount;
		}
		dcount /= 4;
		len /= 2;
	}
	printf("%d", count);
	return 0;
}
