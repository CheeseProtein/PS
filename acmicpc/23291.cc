#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<vector<int>> board(200, vector<int>(200));
int lowest, highest;

int get_diff() {
	lowest = 10000, highest = 0;
	for (int i = 0; i < N; i++) {
		lowest = min(lowest, board[i][0]);
		highest = max(highest, board[i][0]);
	}
	return highest - lowest;
}

void arrange(int here, int w, int h) {
	vector<vector<int>> Up = vector<vector<int>>(200, vector<int>(200));
	vector<vector<int>> Down = vector<vector<int>>(200, vector<int>(200));
	vector<vector<int>> Left = vector<vector<int>>(200, vector<int>(200));
	vector<vector<int>> Right = vector<vector<int>>(200, vector<int>(200));
	int diff;
	for (int x = here; x < here + w; x++) {
		for (int y = 0; y < h - 1; y++) {
			diff = (board[x][y] - board[x][y+1])/5;
			if (diff > 0) Up[x][y] = diff;
		}
	}
	for (int x = here; x < here + w; x++) {
		for (int y = 1; y < h; y++) {
			diff = (board[x][y] - board[x][y-1])/5;
			if (diff > 0) Down[x][y] = diff;
		}
	}
	for (int x = here + 1; x < here + w; x++) {
		for (int y = 0; y < h; y++) {
			diff = (board[x][y] - board[x-1][y])/5;
			if (diff > 0) Left[x][y] = diff;
		}
	}
	for (int x = here; x < here + w - 1; x++) {
		for (int y = 0; y < h; y++) {
			diff = (board[x][y] - board[x+1][y])/5;
			if (diff > 0) Right[x][y] = diff;
		}
	}
	// something left
	int dummy = N - w*h;
	if (dummy > 0) {
		for (int x = here + w; x < here + w + dummy; x++) {
			diff = (board[x][0] - board[x-1][0])/5;
			if (diff > 0) Left[x][0] = diff;
		}
		for (int x = here + w - 1; x < here + w + dummy - 1; x++) {
			diff = (board[x][0] - board[x+1][0])/5;
			if (diff > 0) Right[x][0] = diff;
		}
	}

	// move numbers
	for (int x = here; x < here+w; x++) {
		for (int y = 0; y < h; y++) {
			board[x][y] = board[x][y] - Up[x][y] - Left[x][y] - Right[x][y] - Down[x][y];
			if (x > here) board[x][y] += Right[x-1][y];
			if (x < here+w-1) board[x][y] += Left[x+1][y];
			if (y > 0) board[x][y] += Up[x][y-1];
			if (y < h-1) board[x][y] += Down[x][y+1];
		}
	}

	if (dummy > 0) {
		for (int x = here + w; x < here+w+dummy; x++) {
			board[x][0] = board[x][0] - Left[x][0] - Right[x][0] + Right[x-1][0];
		}
		for (int x = here + w - 1; x < here+w+dummy-1; x++) {
			board[x][0] += Left[x+1][0];
		}
	}

	int there = 0;
	for (int x = here; x < here+w; x++) {
		for (int y = 0; y < h; y++) {
			board[there++][0] = board[x][y];
		}
	}
}

void first_move(int h, int w, int d, int here, int len) {
	int next_h, next_w;
	if (d%2) {
		next_h = h; next_w = w+1;
	} else {
		next_h = h+1; next_w = w;
	}
	int there = here + w;

	if (len < next_w) {
		arrange(here, w, h);
		return;
	}

	for (int x = here; x < here+w; x++) {
		for (int y = 0; y < h; y++) {
			board[there+y][w-x+here] = board[x][y];
		}
	}
	first_move(next_h, next_w, d+1, there, N-there-w);
}

void second_move() {
	for (int x = 0; x < N/2; x++) {
		board[N-x-1][1] = board[x][0];
	}

	for (int y = 0; y <= 1; y++) {
		for (int x = N/2; x < 3*N/4; x++) {
			board[N-1-x+N/2][3-y] = board[x][y];
		}
	}

	arrange(3*N/4, N/4, 4);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> board[i][0];
	}

	int ans;
	for (ans = 0; get_diff() > K; ans++) {
		for (int i = 0; i < N; i++) {
			if (board[i][0] == lowest) board[i][0]++;
		}
		first_move(1, 1, 0, 0, N);
		second_move();
	}
	cout << ans;
	return 0;
}
