#include <bits/stdc++.h>
using namespace std;

vector<int> vertex[26];
int duration[26];
int res;
vector<int> anscestor;

void dfs(int here, int day) {
	res = max(res, day + duration[here]);
	for (int child : vertex[here]) {
		dfs(child, day + duration[here]);
	}
	//cout << "vertex: " << here << ", day: " << day+duration[here] << "\n";
}

int main() {
	string line;
	while (getline(cin, line)) {
		char name_s, parent_s[26];
		int duration_s;
		int ret = sscanf(line.c_str(), "%c %d %s", &name_s, &duration_s, parent_s);

		int name = name_s - 'A';
		duration[name] = duration_s;
		if (ret < 3) {
			anscestor.push_back(name);
			continue;
		}
		string parent = string(parent_s);
		for (char p : parent) {
			int parentname = p - 'A';
			vertex[parentname].push_back(name);
		}
	}
	for (int a : anscestor) {
		dfs(a, 0);
	}
	//cout << "The result is " << res;
	cout << res;
	return 0;
}
