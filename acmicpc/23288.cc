#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<vector<int>> board;
int bot = 6;  // 주사위의 밑면
deque<int> rightQ{3,1,4,6};
deque<int> frontQ{5,1,2,6};

enum {
	DIR_EAST = 0, DIR_SOUTH, DIR_WEST, DIR_NORTH,
	NUM_DIR
};
int dr[NUM_DIR] = {0, 1, 0, -1};
int dc[NUM_DIR] = {1, 0, -1, 0};

pair<int, int> dice{0, 0};  // 주사위 위치

int dir = DIR_EAST;  // 주사위 방향
int score;  // 현재 점수

int bfs(int r, int c) {
	int B = board[r][c];
	int ret = 0;
	queue<pair<int, int>> q;
	q.emplace(r, c);
	vector<vector<int>> visited(N, vector<int>(M));
	visited[r][c] = 1;

	while (!q.empty()) {
		int hereR = q.front().first;
		int hereC = q.front().second;
		q.pop();

		ret += board[hereR][hereC];
		for (int i = 0; i < NUM_DIR; i++) {
			int thereR = hereR + dr[i];
			int thereC = hereC + dc[i];
			if (thereR < 0 || thereR >= N || thereC < 0 || thereC >= M || visited[thereR][thereC] || board[thereR][thereC] != B) continue;
			visited[thereR][thereC] = 1;
			q.push(make_pair(thereR, thereC));
		}
	}
	return ret;
}

int main() {
	cin >> N >> M >> K;
	board = vector<vector<int>>(N, vector<int>(M));
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			cin >> board[n][m];
		}
	}

	for (int k = 0; k < K; k++) {
		// 1. 구르기
RETRY:
		int rr = dice.first + dr[dir];
		int cc = dice.second + dc[dir];
		if (rr < 0 || rr >= N || cc < 0 || cc >= M) {  // 못 가면 반대방향
			dir = (dir + 2) % NUM_DIR;
			goto RETRY;
		}
		dice.first = rr;
		dice.second = cc;

		switch (dir) {
			case DIR_EAST: {
				bot = rightQ.front();
				rightQ.pop_front();
				rightQ.push_back(bot);
				frontQ[1] = rightQ[1];
				frontQ[3] = rightQ[3];
				break;
			}
			case DIR_SOUTH: {
				bot = frontQ.front();
				frontQ.pop_front();
				frontQ.push_back(bot);
				rightQ[1] = frontQ[1];
				rightQ[3] = frontQ[3];
				break;
			}
			case DIR_WEST: {
				rightQ.push_front(bot);
				rightQ.pop_back();
				bot = rightQ.back();
				frontQ[1] = rightQ[1];
				frontQ[3] = rightQ[3];
				break;
			}
			case DIR_NORTH: {
				frontQ.push_front(bot);
				frontQ.pop_back();
				bot = frontQ.back();
				rightQ[1] = frontQ[1];
				rightQ[3] = frontQ[3];
				break;
			}
		}

		// 2. 점수 얻기
		score += bfs(rr, cc);

		// 3. 방향 전환
		if (bot > board[rr][cc]) dir = (dir+1) % NUM_DIR;
		else if (bot < board[rr][cc]) dir = (dir+3) % NUM_DIR;
	}
	cout << score;
	return 0;
}
