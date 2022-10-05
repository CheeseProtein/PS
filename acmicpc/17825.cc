#include <bits/stdc++.h>
using namespace std;

struct Board {
	int score;
	int starts;
	int moves;
} board[33];

bool same_loc(int here, int here_loc, int (&a)[4]) {
	for (int i = 0; i < 3; i++) {
		int there = (here + 1) % 4;
		int there_loc = a[there];
		if (here_loc == there_loc) return true;
	}
	return false;
}

int dice[10];
int max_score;
void move(int (&a)[4], int depth) {  // 각 말의 위치, n번째 move
	int score = board[a[0]].score + board[a[1]].score + board[a[2]].score + board[a[3]].score;
	max_score = max(score, max_score);
	int next_move = dice[depth] - 1;

	int aa[4] = {a[0], a[1], a[2], a[3]};
 	for (int i = 0; i < 4; i++) {  // a b c d
		aa[i] = board[aa[i]].starts;
		for (int j = 0; j < next_move; j++) {
			aa[i] = board[aa[i]].moves;
		}
		// 이전 말과 위치가 같아지면 가지치기
		if (same_loc(i, aa[i], a)) continue;
		move(aa, depth+1);
	}
}

int main() {
	for (int i = 0; i <= 31; i++) {
		board[i].score = i*2;
		board[i].starts = i+1;
		board[i+1].moves = i+1;
	}
	board[5].starts = 21;
	board[10].starts = 24;
	board[15].starts = 26;
	board[20].starts = board[20].moves = 32;
	board[21].score = 13;
	board[22].score = 16;
	board[23].score = 19; board[23].starts = board[23].moves = 29;
	board[24].score = 22;
	board[25].score = 24; board[25].starts = board[25].moves = 29;
	board[26].score = 28;
	board[27].score = 27;
	board[28].score = 26;
	board[29].score = 25;
	board[30].score = 30;
	board[31].score = 35; board[31].starts = board[31].moves = 20;
	board[32].score = 0; board[32].starts = board[32].moves = 32;

	for (int i = 0; i < 10; i++) {
		scanf("%d", &dice[i]);
	}
	int arr[4] = {0,0,0,0};
	move(arr, 0);
	printf("%d", max_score);
	return 0;
}
