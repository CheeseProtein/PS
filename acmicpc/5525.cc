#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
string S;

/**
 * 50점 짜리 코드
 */
 // int main() {
 //     ios::sync_with_stdio(false);
 //     cin.tie(NULL);
 //     cout.tie(NULL);

 //     cin >> N >> M >> S;
 //     string pn = "I";
 //     for (int i = 0; i < N; ++i) {
 //         pn += "OI";
 //     }
 //     int len = pn.size();

 //     int result = 0;
 //     for (int i = 0; i <= S.size() - len; ++i) {
 //         // cout << "Comparing " << S.substr(i, len) << "... \n";
 //         if (S.substr(i, len) == pn) 
 //             ++result;
 //     }
 //     cout << result;
 //     return 0;
 // }

vector<int> getPi(string& str) {
    int size = str.size();
    vector<int> pi(size, 0);
    int begin = 1, match = 0;
    while (begin + match < size) {
        if (str[begin + match] == str[match]) {
            ++match;
            pi[begin + match - 1] = match;
        }
        else {
            if (!match) {
                ++begin;
            }
            else {
                begin += match - pi[match - 1];
                match = pi[match - 1];
            }
        }
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> S;

    string pn = "I";
    for (int i = 0; i < N; ++i) {
        pn += "OI";
    }

    vector<int> pi = getPi(pn);
    int begin = 0, matched = 0, result = 0;
    while (begin <= S.size() - pn.size()) {
        if (matched < pn.size() && S[begin + matched] == pn[matched]) {
            ++matched;
            if (matched == pn.size()) ++result;
        }
        else {
            if (!matched) {
                ++begin;
            }
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    cout << result << endl;
    return 0;
}