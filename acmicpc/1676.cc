#include <iostream>

int N;

int main() {
    scanf("%d", &N);
    int result = N / 5 + N / 25 + N / 125;
    printf("%d", result);
    return 0;
}