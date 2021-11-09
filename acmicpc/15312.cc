#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> name;
int alpha[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
string A, B;
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	// CJM, HER -> 1 2 2 / 3 3 2 = 1 3 2 3 2 2
	// 4 5 5 5 4
	// 9 0 0 9
	// 9 0 9
	// 9 9
	int len = A.length() * 2;
	vector<int> init;
	for (int i = 0; i < len; i += 2) {
		init.push_back(alpha[A[i/2]-65]);
		init.push_back(alpha[B[i/2]-65]);
	}
	name.push_back(init);

	for (int i = len - 1; i >= 2; --i) {
		int before = name.size() - 1;
		vector<int> next;
		for (int j = 0; j < i; ++j) {
			next.push_back((name[before][j] + name[before][j+1])%10);
		}
		name.push_back(next);
	}

	cout << name[name.size()-1][0] << name[name.size()-1][1];
	return 0;
}