#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int N, One, Two;
int Longest, Result;
vector<pair<int, int>> adj[100000];  // connected vertex, weight
bool visited[100000];

void dfs(int here, int longest, int dist) {
  for (size_t i = 0; i < adj[here].size(); ++i) {
    int there = adj[here][i].first;
    int cost = adj[here][i].second;

    if (there == Two) {
      Longest = max(longest, cost);
      Result = dist + cost - Longest;
      return;
    }

    if (!visited[there]) {
      visited[there] = true;
      dfs(there, max(longest, cost), dist + cost);
    }
  }
}

int main() {
  memset(visited, false, sizeof visited);
  scanf("%d%d%d", &N, &One, &Two);
  --One; --Two;
  for (int i = 0; i < N - 1; ++i) {
    int start, end, weight;
    scanf("%d%d%d", &start, &end, &weight);
    adj[start - 1].push_back(make_pair(end - 1, weight));
    adj[end - 1].push_back(make_pair(start - 1, weight));
  }
  visited[One] = true;
  dfs(One, 0, 0);
  if (One == Two) printf("0");
  else printf("%d", Result);
  return 0;
}
