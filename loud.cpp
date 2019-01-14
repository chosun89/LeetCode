#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
const int inf = 0x3f3f3f3f;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
      int n = quiet.size();
      vector<int> g[n];

      // construct a digraph of increasing richness (opposite order)
      FOR(i,0,richer.size()) {
        auto p = richer[i];
        g[p[1]].pb(p[0]);
      }

      // res stores VERTEX of minimum quietness starting from res[i]
      vector<int> res(n,inf);

      FOR(i,0,n) {
        if (res[i] == inf)
          res[i] = dfs(g,res,quiet,i);
      }
      return res;
    }

    // always returns the VERTEX of minimum quietness in ALL paths (dfs)
    int dfs (vector<int> g[], vector<int>& res, vector<int>& quiet, int u) {
      if (res[u] != inf) return res[u];
      if (g[u].empty()) {
        return res[u] = u;
      }
      res[u] = u;
      for (auto v : g[u]) {
        int d = dfs(g,res,quiet,v);
        if (quiet[d] < quiet[ res[u] ]) {
          res[u] = d;
        }
      }
      return res[u];
    }
};

int main() {
  Solution s;
  //vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
	//vector<int> quiet = { 3,2,5,4,6,1,7,0 };
  vector<vector<int>> richer = { {0,1} };
  vector<int> quiet = { 1, 0 };
  vector<int> res = s.loudAndRich(richer,quiet);
	for (auto a : res) cout << a  << " ";


}

