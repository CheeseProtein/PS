#include <iostream>
#include <cmath>
using namespace std;

int cur = 100;
int N, M;
int normal[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int digits(int num) {
    int i;
    for (i = 0; num > 0; ++i) {
        num /= 10;
    }
    return i == 0 ? 1 : i;
}

bool check(int num) {
    int digit = digits(num);
    for (int i = 0; i < digit; ++i) {
        if (!normal[num % 10]) return false;
        num /= 10;
    }
    return true;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int m = 0; m < M; ++m) {
        int br;
        scanf("%d", &br);
        normal[br] = 0;
    }
    if (N == 100) {
        printf("0");
    }
    else if (N == 99 || N == 101) {
        printf("1");
    }
    else if (N == 98 || N == 102) {
        printf("2");
    }
    else {
        int max = abs(N - 100);
        int i;
        for (i = 0; i < max; ++i) {
            if ((N - i >= 0) && check(N - i) && (digits(N - i) + i) < max) {
                printf("%d", digits(N - i) + i);
                return 0;
            }
            if (check(N + i) && (digits(N + i) + i) < max) {
                printf("%d", digits(N + i) + i);
                return 0;
            }
        }
        printf("%d", i);
    }
    return 0;
}
