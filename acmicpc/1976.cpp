#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj = vector<vector<int>>(N, vector<int>(N));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> adj[r][c];
        }
    }

    vector<int> route = vector<int>(M);
    for (int m = 0; m < M; m++) {
        int input;
        cin >> input;
        if (input > N) {
            cout << "NO" << endl;
            return 0;
        }
        
        route[m] = input - 1;
    }

    queue<int> q;
    vector<bool> visited = vector<bool>(N);
    q.push(route[0]);
    visited[route[0]] = true;
    while (!q.empty()) {
        int here = q.front();
        q.pop();

        for (int n = 0; n < N; n++) {
            if (!adj[here][n] || visited[n]) continue;
            visited[n] = true;
            q.push(n);
        }
    }

    for (int m = 0; m < M; m++) {
        if (!visited[route[m]]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}