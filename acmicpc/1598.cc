/**
 * Solve a mathematics prob with NPC (week 2)
 */
#include <iostream>
#include <cmath>

int Big, Small;
int Rowdiff, Coldiff;

int Rowpos(int num) {
    return num % 4 == 0 ? 4 : num % 4;
}

int Colpos(int num) {
    return num % 4 == 0 ? num / 4 - 1 : num / 4;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) {
        Big = x;
        Small = y;
    }
    else {
        Big = y;
        Small = x;
    }
    Coldiff = Colpos(Big) - Colpos(Small);
    Rowdiff = abs(Rowpos(Big) - Rowpos(Small));
    printf("%d", Coldiff + Rowdiff);
    return 0;
}
