/**
 * PROGRAMMERS.CO.KR
 * Brute Force
 * Carpet
 * Submitted on June 17, 2021.
 *
 * NOTE: This answer was written after checking the answers of other people.
 */
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int x, y;
    for (y = 3; y <= x; ++y) {
        x = brown / 2 + 2 - y;
        
        printf("Testing x:%d y:%d\n", x, y);
        if ((x - 2) * (y - 2) == yellow)
            break;
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}
