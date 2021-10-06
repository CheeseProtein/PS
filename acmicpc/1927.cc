#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		int op;
		scanf("%d", &op);
		if (op) {
			pq.emplace(-op);
		} else {
			if (pq.size() == 0) {
				printf("0\n");
			} else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}
