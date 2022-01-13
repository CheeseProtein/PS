// BFS
#include <bits/stdc++.h>
using namespace std;

bool sim(string orig, string app) {
    bool diff = false;
    int o = 0, a = 0;
    while (o < orig.length()) {
        if (orig[o] != app[a]) {
            if (!diff) {
                diff = true;
                ++a;
            } else {
                return false;
            }
        } else {
            ++o, ++a;
        }
    }
    if (a < app.length()) {
        if (diff) return false;
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int d;
    string first;
    cin >> d >> first;
    vector<string> words[81];
	int longest = 3;
    for (int i = 0; i < d; ++i) {
        string input;
        cin >> input;
        words[input.size()].push_back(input);
		longest = max(longest, (int) input.size());
    }

	queue<string> q; q.push(first);
	string longest_word = first;
	while (!q.empty()) {
		string here = q.front();
		q.pop();
		for (auto there = words[here.size() + 1].begin(); there != words[here.size() + 1].end(); ) {
			if (sim(here, *there)) {
				q.push(*there);
				if (longest_word.size() < there->size()) {
					longest_word = *there;
				}
				words[here.size() + 1].erase(there);
			} else {
				++there;
			}
		}
	}
	cout << longest_word;
	return 0;
}