#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /*int findRotateSteps(string ring, string key) {
      int R = ring.size();
      int K = key.size();
      vector<int> pos[26];
      for (int i = 0; i < R; i++) pos[ring[i] - 'a'].push_back(i);
      
      int dp[K + 1][R + 1];
      memset(dp, 0x3f, sizeof(dp));
      memset(dp[0], 0, sizeof(dp[0]));

      int res = 0x3f3f3f3f;
      vector<int> nxt(1, 0);
      for (int i = 1; i <= K; i++) {
        for (auto k : pos[ key[i-1] - 'a']) {
          for (int j = 0; j < nxt.size(); j++) {
            int dist = abs (nxt[j] - k);
            dp[i][k] = min (dp[i][k], dp[i-1][ nxt[j] ] + min(dist, R - dist));
            res = (i != K) ? res : min(res, dp[i][k]);
          }
        }
        nxt = pos[ key[i - 1] - 'a'];
      }
      return res + K;
    }*/

    int findRotateSteps(string ring, string key) {
      int m = ring.size();
      int n = key.size();
      vector<int> amap[26];
      for (int i = 0; i < m; i++) {
          amap[ ring[i]- 'a' ].push_back(i);
      }
      
      vector< vector<int> > dp(n, vector<int>(m));
      return recurse(0, 0, ring, key, amap, dp);
    }

    int recurse (int idK, int idR, string& ring, string& key, vector<int> amap[], vector<vector<int>>& dp) {
      if (idK == key.size()) return 0;
      if (dp[idK][idR]) return dp[idK][idR];
      
      int mini = INT_MAX;
      int R = ring.size();
      for (int k : amap[ key[idK] - 'a']) {
          int diff = abs(k - idR);
          mini = min (mini , min(diff, R - diff) + recurse(idK + 1, k, ring, key, amap, dp));
      }
      return  dp[idK][idR] = mini + 1;
    }

};

int main() {

  string s1 = "hellowworld";
  string s2 = "hwrd";
  string s3 = "godding";
  string s4 = "gd";
  Solution sol;
  cout << sol.findRotateSteps(s1, s2) << endl;
}


