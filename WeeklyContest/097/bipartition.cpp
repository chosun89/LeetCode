#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  const int maxn = 2010;
    vector<int> g[2010];

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      for (auto r : dislikes) {
        int u = r[0];
        int v = r[1];
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
      }

      vector<int> visit(N, 0);
      for (int i = 0; i < N; i++) {
        if (visit[i]) continue;
        else {
          if (!dfs(i, visit, 0)) return false;
        }
      }
      return true;
    }

    bool dfs(int u, vector<int>& visit, int k) {
      if (visit[u] != -1) return visit[u] == k;
      visit[u] = k;
      for (auto v : g[u]) {
        if (!dfs(v, visit, k ^ 1)) return false;
      }
      return true;
    }
};

int main() {
  Solution s;
  vector<vector<int>> g = { {1,2}, {1,3}, {1,4}, {1,5} };
  cout << s.possibleBipartition(5, g) << endl;
}
