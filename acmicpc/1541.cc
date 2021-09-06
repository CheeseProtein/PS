#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    vector<int> numbers;
    vector<char> op;
    int start = 0;

    int subsum = 0;
    int sum = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == '+') {
            subsum += input[i];
        } else if (input[i] == '-' && sum) {
            sum -= subsum;
            subsum = 0;
        } else if (input[i] == '-' && !sum) {
            sum = subsum;
            subsum = 0;
        }

        if (input[i] == '+' || input[i] == '-') {
            numbers.push_back(stoi(input.substr(start, i)));
            start = i + 1;
            op.push_back(input[i]);
        }
    }
    numbers.push_back(stoi(input.substr(start, input.size())));

    int leader = 0;
    for (int i = 0; i < op.size(); ++i) {
        if (op[i] == '+') {
            numbers[leader] += numbers[i + 1];
            numbers[i + 1] = 0;
        } else {
            leader = i + 1;
        }
    }

    int result = numbers[0];
    for (int i = 1; i < numbers.size(); ++i) {
        result -= numbers[i];
    }

    cout << result;
    return 0;
}