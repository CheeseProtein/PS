#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int>(n, 987654321));
    dist[0][0] = 0;

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
    q.push({0, 0, 0}); // cost, r, c

    int res = 987654321;
    while (!q.empty()) {
        vector<int> here = q.top();
        q.pop();
        int hereCost = here[0];
        int hereR = here[1];
        int hereC = here[2];

        if (dist[hereR][hereC] < hereCost) continue;

        if (hereR == n-1 && hereC == n-1) {
            res = hereCost;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int rr = hereR + dr[i];
            int cc = hereC + dc[i];

            if (rr < 0 || rr >= n || cc < 0 || cc >= n) continue;

            int cost = board[rr][cc] == '1' ? 0 : 1;

            if (dist[rr][cc] > hereCost + cost) {
                dist[rr][cc] = hereCost + cost;
                q.push({dist[rr][cc], rr, cc});
            }
        }
    }

    cout << res << endl;
    return 0;
}
