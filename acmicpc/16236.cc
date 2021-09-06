#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int board[20][20];
int visited[20][20];
int X, Y;
int Size = 2;
int Eat = 0;
int Count = 0;
int Moves = 0;

bool Move() {
    queue<pair<pair<int, int>, int>> q;
    vector<pair<int, int>> target;
    int max_moves = 99999;
    int moves = 0;
    do {
        if (!q.empty()) {
            X = q.front().first.first;
            Y = q.front().first.second;
            moves = q.front().second;
            // printf("Now searching %d %d\n", X, Y);
        }
        if (0 < board[Y][X] && board[Y][X] < Size && moves <= max_moves) {
            target.push_back(make_pair(Y, X));
            max_moves = moves;
        }
        if (!q.empty())
            q.pop();

        if (moves < max_moves) {
            for (int i = 0; i < 4; ++i) {
                if ((0 <= X + dx[i] && X + dx[i] < N) &&
                    (0 <= Y + dy[i] && Y + dy[i] < N) &&
                    !visited[Y + dy[i]][X + dx[i]] &&
                    (0 <= board[Y + dy[i]][X + dx[i]] && board[Y + dy[i]][X + dx[i]] <= Size)) {
                    visited[Y + dy[i]][X + dx[i]] = 1;
                    q.push(make_pair(make_pair(X + dx[i], Y + dy[i]), moves + 1));
                }
            }
        }
    } while (!q.empty());

    if (target.empty()) {
        return false;
    }
    else {
        sort(target.begin(), target.end());
        X = target.front().second;
        Y = target.front().first;
        board[Y][X] = 0;
        ++Eat; ++Count;
        Moves += max_moves;
        if (Count == Size) {
            ++Size;
            Count = 0;
        }
        // printf("Got one at %d %d, Eat %d, Size %d with %d moves\n", X, Y, Eat, Size, Moves);
        return true;
    }

    // 이동할 수 있는 칸이 없고, 먹을 게 없으면 중단
    return false;
}

int main() {
    memset(board, -1, sizeof board);
    memset(visited, 0, sizeof visited);
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &board[i][j]);
            if (board[i][j] == 9) {
                X = j;
                Y = i;
                board[i][j] = 0;
                visited[i][j] = 1;
            }
        }
    }

    while (true) {
        bool move = Move();
        if (!move) break;
        else {
            memset(visited, 0, sizeof visited);
            visited[Y][X] = 1;
        }
    }

    printf("%d\n", Moves);
    return 0;
}
