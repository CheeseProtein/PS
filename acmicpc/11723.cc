#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int M;
	int set = 0;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		char op[10];
		int x;
		scanf("%s", op);
		if (!strcmp(op, "add")) {
			scanf("%d", &x);
			set |= (1 << x);	
		} else if (!strcmp(op, "remove")) {
			scanf("%d", &x);
			set &= ~(1 << x);
		} else if (!strcmp(op, "check")) {
			scanf("%d", &x);
			if (set & (1 << x)) printf("1\n");
			else printf("0\n");
		} else if (!strcmp(op, "toggle")) {
			scanf("%d", &x);
			set ^= (1 << x);
		} else if (!strcmp(op, "all")) {
			set = (1 << 21) - 1;
		} else if (!strcmp(op, "empty")) {
			set = 0;
		}
	}
	return 0;
}