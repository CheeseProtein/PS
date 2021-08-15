/**
 * PROGRAMMERS.CO.KR
 * BFS
 * Word Conversion
 * Submitted on July 16, 2021.
 * Execution time: 0.01ms ~ 0.04ms
 */
#include <string>
#include <vector>

#include <iostream>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    vector<string> items = {begin};
    for (auto &i : words)
        items.push_back(i);
    
    vector<vector<bool>> matrix;
    for (auto &item : items) {
        vector<bool> row;
        for (int i = 0; i < items.size(); ++i) {
            int diff = 0;
            for (int j = 0; j < item.size(); ++j) {
                if (item[j] != items[i][j])
                    ++diff;
            }
            if (diff == 1)
                row.push_back(true);
            else
                row.push_back(false);
        }
        matrix.push_back(row);
    }
    
    /*for (auto &i : matrix) {
        for (bool j : i) {
            printf("%d", j);
        }
        printf("\n");
    }*/
    
    vector<int> distance(matrix.size(), -1);
    distance[0] = 0;
    
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        for (int i = 0; i < matrix[here].size(); ++i) {
            if (matrix[here][i] && distance[i] == -1) {
                q.push(i);
                distance[i] = distance[here] + 1;
                if (items[i] == target) {
                    return distance[i];
                }
                // cout << items[i] << ":" << target << endl;
            }
        }
    }
    
    for (auto &i: distance) printf("%d", i);
    
    
    int answer = 0;
    return answer;
}
