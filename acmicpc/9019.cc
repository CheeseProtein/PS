#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int T, A, B;
int visit[10000];

void search() {
    memset(visit, 0, sizeof visit);
    queue<pair<int, string>> q;
    q.push(make_pair(A, ""));
    visit[A] = 1;

    while (!q.empty()) {
        int num = q.front().first;
        string op = q.front().second;
        q.pop();
        if (num == B) {
            cout << op << endl;
            return;
        }
        int d = num * 2 % 10000;
        int s = num ? num - 1 : 9999;
        int l = num % 1000 * 10 + num / 1000;
        int r = num % 10 * 1000 + num / 10;
        if (!visit[d]) {
            q.push(make_pair(d, op + 'D')); visit[d] = 1;
        }
        if (!visit[s]) {
            q.push(make_pair(s, op + 'S')); visit[s] = 1;
        }
        if (!visit[l]) {
            q.push(make_pair(l, op + 'L')); visit[l] = 1;
        }
        if (!visit[r]) {
            q.push(make_pair(r, op + 'R')); visit[r] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A >> B;
        search();
    }
    return 0;
}
