#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int N, M;
map<string, int> list;
map<int, string> list2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    string name;
    for (int i = 1; i <= N; ++i) {
        cin >> name;
        list.insert(make_pair(name, i));
        list2.insert(make_pair(i, name));
    }
    for (int i = 0; i < M; ++i) {
        cin >> name;
        if (isdigit(name[0])) {
            cout << list2[stoi(name)] << '\n';
        }
        else {
            cout << list[name] << '\n';
        }
    }
    return 0;
}