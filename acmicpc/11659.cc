#include <iostream>
using namespace std;

int N;
int M;

int main() {
    int sum[100001] = { 0 };
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i) {
        int input;
        scanf("%d", &input);
        sum[i] = sum[i - 1] + input;
    }
    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }
    return 0;
}