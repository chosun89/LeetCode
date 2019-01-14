#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
      int m = s1.size();
      int n = s2.size();
      int dp[m + 1][n + 1];
      memset(dp,0,sizeof(dp));
      FOR(i,1,m+1) dp[i][0] = dp[i-1][0] + s1[i-1];
      FOR(i,1,n+1) dp[0][i] = dp[0][i-1] + s2[i-1];

      FOR(i, 1, m+1) FOR(j, 1, n+1) {
        if (s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1];
        else {
          dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
        }
      }
      return dp[m][n];  
    }
};

int main() {

  Solution sol;
  string s1 = "delete";
  string s2 = "leet";
  cout << sol.minimumDeleteSum(s1,s2) << endl;

}

