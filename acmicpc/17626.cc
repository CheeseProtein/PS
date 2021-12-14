#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int mem[50001];
int n;
int find(int n) {
    int &ret = mem[n];
    if (ret) return ret;
    int bound = sqrt(n);
    ret = 5;
    for (int i = 0; i <= bound / 2; ++i) {
        int here = (bound - i) * (bound - i);
        ret = min(ret, 1 + find(n - here));
    }
    return ret;
}
int main() {
    scanf("%d", &n);
    memset(mem, 0, sizeof mem);
    int bound = sqrt(n);
    for (int i = 1; i <= bound; ++i) {
        mem[i * i] = 1;
    }
    printf("%d", find(n));
    return 0;
}
