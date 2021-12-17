#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int alpha[26] = { 0 };

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// memset(alpha, -1, sizeof alpha);
	int N;
	cin >> N;

	for (int n = 0; n < N; ++n) {
		string input;
		cin >> input;
		int decimal = 1;
		for (int i = input.size() - 1; i >= 0; --i) {
			char here = input[i];
			alpha[here - 65] += decimal;
			decimal *= 10;
		}
	}

	vector<int> inputs;
	for (int i = 0; i < 26; ++i) {
		if (!alpha[i]) continue;
		inputs.push_back(alpha[i]);
	}
	sort(inputs.begin(), inputs.end());

	int result = 0;
	int num = 9;
	for (int i = inputs.size() - 1; i >= 0; --i) {
		result += inputs[i] * num;
		num--;
	}
	cout << result;
	return 0;
}