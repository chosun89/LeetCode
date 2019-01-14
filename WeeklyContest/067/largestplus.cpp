#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
      vector<vector<int>> dp(N, vector<int>(N, N));
      for ( auto m : mines)
        dp[ m[0]][ m[1]] = 0;

      for (int i = 0; i < N; i++) {
        int l,r,t,b = 0;
        int k = N - 1;
        for (int j = 0; j < N; j++) {
          l = valid (dp[i][j], l);
          dp[i][j] = min (dp[i][j], l);

          r = valid (dp[i][k], r);
          dp[i][k] = min (dp[i][k], r);

          t = valid (dp[j][i], t);
          dp[j][i] = min (dp[j][i], t);
          
          b = valid (dp[k][i], b);
          dp[k][i] = min (dp[k][i], b);

          k--;
        }
      }

      int maxi = 0;
      FOR(i,0,N) FOR(j,0,N) 
        if (dp[i][j] > maxi) 
          maxi = dp[i][j];
      return maxi;
    }

    int valid (int x, int y) {
      if (x == 0) return 0;
      else return y + 1;
    }
};

int main() {
  Solution s;
  vector<vector<int>> mines = {{0,0}};
  cout << s.orderOfLargestPlusSign(1,  mines) << endl;

}

