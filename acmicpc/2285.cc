/**
 * Solve an implementation prob with NPC (week 2)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long Sum;
int Result;
vector<pair<int, int>> Pair;  // location, num of people

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int x, a;
        scanf("%d%d", &x, &a);
        Sum += a;
        Pair.push_back(make_pair(x, a));
    }
    sort(Pair.begin(), Pair.end());
    Sum % 2 ? (Sum = Sum / 2 + 1) : (Sum = Sum / 2);
    long long sum = 0;
    for (size_t i = 0; i < Pair.size(); ++i) {
        sum += Pair[i].second;
        if (sum >= Sum) {
            printf("%d", Pair[i].first);
            return 0;
        }
    }
}
