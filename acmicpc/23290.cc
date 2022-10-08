#include <bits/stdc++.h>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int M;
int S;
int cur_fishes;        // number of fishes
int old_fishes;
vector<vector<int>> smell;  // smell[4][4]
vector<vector<vector<int>>> board;  // board[4][4]
vector<vector<vector<int>>> old_board;  // old_board[4][4];
vector<vector<vector<int>>> new_board;
pair<int, int> jaws;   // location of jaws

void move_fish(int r, int c, int i_th) {
	int dir = board[r][c][i_th];
	for (int i = 0; i < 8; i++) {
		int rr = r + dy[dir-1];
		int cc = c + dx[dir-1];
		if (0 <= rr && rr < 4 &&
			0 <= cc && cc < 4 &&
			!(rr == jaws.first && cc == jaws.second) &&
			smell[rr][cc] == 0) {  // then move to..
			new_board[rr][cc].push_back(dir);
			board[r][c][i_th] = 0;  // move done. deletes on compaction
			return;
		}
		// else, change dir and retry
		dir = (dir == 1) ? (8) : (dir-1);
	}
}

enum JAWS_DIR {
	UP, LEFT, DOWN, RIGHT
};
int ddx[4] = {0, -1, 0, 1};
int ddy[4] = {-1, 0, 1, 0};
string jdir[4] = {"u", "l", "d", "r"};
int max_fishes;
string max_route;
void dfs(int row, int col, string route, int ate, vector<vector<vector<int>>> now_board) {
	// int hereAte = ate + now_board[row][col].size();
	// now_board[row][col] = vector<int>();

	if (route.size() == 3) {
		if (max_fishes < ate) {
			max_fishes = ate;
			max_route = route;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		int rr = row + ddy[i];
		int cc = col + ddx[i];
		if (0 <= rr && rr < 4 && 0 <= cc && cc < 4) {
			int thereAte = now_board[rr][cc].size();
			now_board[rr][cc] = vector<int>();

			dfs(rr, cc, route + jdir[i], ate + thereAte, now_board);
		}
	}
}

int main() {
	cin >> M >> S;
	board = vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>()));
	smell = vector<vector<int>>(4, vector<int>(4));
	for (int m = 0; m < M; m++) {
		int fx, fy, d;
		cin >> fx >> fy >> d;
		board[fx-1][fy-1].push_back(d);
	}
	cur_fishes = M;
	int x, y;
	cin >> x >> y;
	jaws = pair<int, int>{x-1, y-1};

	for (int s = 0; s < S; s++) {
		// 1
		old_board = board;
		old_fishes = cur_fishes;
		// 2
		new_board = vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>()));
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				for (size_t i = 0; i < board[row][col].size(); i++) move_fish(row, col, i);
			}
		}
		// 2-compaction
		for (int row = 0; row < 4; row++) {
			for (int col = 0; col < 4; col++) {
				for (size_t i = 0; i < board[row][col].size(); i++) {
					if (board[row][col][i]) new_board[row][col].push_back(board[row][col][i]);
				}
			}
		}
		board = new_board;
		// 3
		max_fishes = -1;
		max_route = "";
		dfs(jaws.first, jaws.second, "", 0, board);
		for (int i = 0; i < 3; i++) {
			char hereMove = max_route[i];
			for (int j = 0; j < 4; j++) {
				if (hereMove != jdir[j][0]) continue;
				int rr = jaws.first + ddy[j];
				int cc = jaws.second + ddx[j];
				if (board[rr][cc].size()) {		// if there were any fish
					cur_fishes -= board[rr][cc].size();
					board[rr][cc] = vector<int>();
					smell[rr][cc] = 3;
				}
				jaws = pair<int, int>{rr, cc};
			}
		}
		// 4
		for (int r = 0; r < 4; r++) for (int c = 0; c < 4; c++) {
			if (smell[r][c] > 0) smell[r][c] -= 1;
		}
		// 5
		cur_fishes += old_fishes;
		for (int r = 0; r < 4; r++) for (int c = 0; c < 4; c++) {
			for (auto f : old_board[r][c]) board[r][c].push_back(f);
		}
	}
	cout << cur_fishes;
	return 0;
}
