#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int friends[100][100];

int main() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (i == j) friends[i][j] = 0;
			else friends[i][j] = 99;
		}
	}
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		friends[a-1][b-1] = friends[b-1][a-1] = 1;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				friends[j][k] = min(friends[j][k], friends[j][i] + friends[i][k]);
			}
		}
	}
	int result = 99, person;
	for (int i = 0; i < N; ++i) {
		int temp = 0;
		for (int j = 0; j < N; ++j) {
			temp += friends[i][j];
		}
		if (temp < result) { 
			person = i;
			result = temp;
		}
	}
	printf("%d", person + 1);
	return 0;
}
