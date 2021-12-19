#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	priority_queue<int> pq;
	for (int n = 0; n < N; ++n) {
		int input; scanf("%d", &input);
		pq.push(-1 * input);
	}
	int total = 0;
	while (pq.size() > 1) {
		int one = -1 * pq.top(); pq.pop();
		int two = -1 * pq.top(); pq.pop();
		total += one + two;
		pq.push(-1 * (one + two));
	}
	printf("%d", total);
	return 0;
}