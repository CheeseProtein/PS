/**
 * Dynamic Programming - 1
 * 1003. The Fibonacci Function
 */
#include <iostream>

int ones[41] = { 0, 1, 1 };
int zeros[41] = { 1, 0, 1 };

void Fibo(int n) {
    if (n < 3) {
        return;
    }
    if (!ones[n-2] || !zeros[n-2]) {
        Fibo(n-2);
    }
    if (!ones[n-1] || !zeros[n-1]) {
        Fibo(n-1);
    }

    if (!ones[n]) {
        ones[n] = ones[n-2] + ones[n-1];
    }
    if (!zeros[n]) {
        zeros[n] = zeros[n-2] + zeros[n-1];
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int N;
        scanf("%d", &N);
        Fibo(N);
        printf("%d %d\n", zeros[N], ones[N]);
    }
    return 0;
}
