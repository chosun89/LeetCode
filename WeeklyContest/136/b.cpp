#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {

      vector<vector<int>> g(N);
      vector<int> res(N,0);

      for (auto p : paths) {
        int x = p[0] - 1;
        int y = p[1] - 1;
        g[x].pb(y);
        g[y].pb(x);
      }

      for (int v = 0; v < N; v++) {
        set<int> neigh;
        for(auto u : g[v]) neigh.emplace(res[u]);

        for (int i = 1; i <= 4; i++) {
          if (neigh.find(i) == neigh.end()) 
          {
            res[v] = i;
            break;
          }
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<vector<int>> paths = { {1,2}, {2,3}, {3,1} };
  vector<int> res = s.gardenNoAdj(3,  paths);
  for (auto c : res) cout << c << endl;

}

