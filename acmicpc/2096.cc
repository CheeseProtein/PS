#include <iostream>
#include <cstring>
using namespace std;

int board[100'000][3];
int maxima[3] = {0, 0, 0};
int minima[3] = {0, 0, 0};

int main() {
	memset(board, 0, sizeof board);
	int N; cin >> N;
	for (int n = 0; n < N; n++) cin >> board[n][0] >> board[n][1] >> board[n][2];
	for (int i = 0; i < N; i++) {
		int nextMax[3] = {maxima[0], maxima[1], maxima[2]};
		int nextMin[3] = {minima[0], minima[2], minima[2]};
		nextMax[0] = board[i][0] + max(maxima[0], maxima[1]);
		nextMax[1] = board[i][1] + max(maxima[0], max(maxima[1], maxima[2]));
		nextMax[2] = board[i][2] + max(maxima[1], maxima[2]);

		nextMin[0] = board[i][0] + min(minima[0], minima[1]);
		nextMin[1] = board[i][1] + min(minima[0], min(minima[1], minima[2]));
		nextMin[2] = board[i][2] + min(minima[1], minima[2]);

		for (int j = 0; j < 3; j++) {
			maxima[j] = nextMax[j];
			minima[j] = nextMin[j];
		}
		//printf("#%d: max %d %d %d, min %d %d %d\n", i,maxima[0], maxima[1],maxima[2], minima[0], minima[1], minima[2]);
	}
	printf("%d %d\n", max(maxima[0], max(maxima[1], maxima[2])), min(minima[0], min(minima[1], minima[2])));
	return 0;
}
