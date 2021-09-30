/**
 * Solve an implementation prob with NPC (week 2)
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> spin(10);
    int D;
    while (true) {
        char buffer[15];    
        if (scanf("%s", buffer) == EOF) break;
        for (int i = 0; i <= 10; ++i) {
            if (buffer[i] == '\0') {
                D = i;
                break;
            }
            if (isdigit(buffer[i])) {
                spin[i] = (spin[i] + (int)buffer[i] - 48) % 10;
            }
        }
    }
    for (int i = 0; i < D; ++i) {
        printf("%d", spin[i]);
    }
    return 0;
}
