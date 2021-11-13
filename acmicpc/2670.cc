#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<double> num{1};
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		double input;
		scanf("%lf", &input);
		double next = max(input, input * num[num.size()-1]);
		num.push_back(next);
	}
	num.erase(num.begin());
	sort(num.begin(), num.end());
	printf("%.3lf", num[num.size()-1]);
	return 0;
}