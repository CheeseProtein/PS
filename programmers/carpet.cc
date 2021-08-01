/**
 * PROGRAMMERS.CO.KR
 * Brute Force
 * Carpet
 * Submitted on June 17, 2021.
 */
#include <string>
#include <vector>

using namespace std;

bool found = false;
int yellowG, brownG;
int ans1, ans2;

void pop(vector<int> factor, int n, int x) {
    if (found) return;
        
    if (!n) {
        ans2 = brownG/2 + 2 - x;
        if ((x - 2) * (ans2 - 2) == yellowG) {
            ans1 = x;
            found = true;
        }
    } else {
        for (int i = 0; i <= factor.size() - n; ++i) {
            if (found) return;
            
            int next_x = x * factor[i];
            vector<int> next_factor = factor;
            next_factor.erase(next_factor.begin() + i);         
            pop(next_factor, n - 1, next_x);
        }
    }
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<int> factor;
    
    // 1. Factoring
    int xy = yellow + brown;
    yellowG = yellow;
    brownG = brown;
    
    for (int i = 2; i * i <= xy; ++i) {
        while (xy % i == 0) {
            factor.push_back(i);
            xy /= i;
        }
    }
    if (xy > 1) factor.push_back(xy);
    
    // 2. Finding combinations
    for (int n = 1; n < factor.size(); ++n) {
        int x = 1;
        pop(factor, n, x);
    }
    
    int bigger = ans1 > ans2 ? ans1 : ans2;
    int smaller = ans1 > ans2 ? ans2 : ans1;
    
    answer.push_back(bigger);
    answer.push_back(smaller);
    
    return answer;
}
