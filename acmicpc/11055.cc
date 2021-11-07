#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> num;
vector<int> mem;

int main() {
    scanf("%d", &N);
    mem = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
        int n;
        scanf("%d", &n);
        num.push_back(n);
    }

    for (int i = 0; i < N; ++i) {
        mem[i] = num[i];
        for (int j = 0; j < i; ++j) {
            if (num[i] > num[j] && mem[i] < mem[j] + num[i]) {
                mem[i] = mem[j] + num[i];
            }
        }
    }

    sort(mem.begin(), mem.end());
    printf("%d", mem[N - 1]);
    return 0;
}
