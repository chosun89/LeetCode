#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();
    if (n == 0) return 1;
    int dp[n][n];
    bool isP[n][n];
    memset(dp, 0, sizeof(dp));
    memset(isP,false,sizeof(isP));

    // len = 1 palindrome
    for (int i = 0; i < n; i++) {
      //dp[i][i] = 1;
      isP[i][i] = true;
    }
    // len = 2
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i+1]){
        dp[i][i+1] = 1;
        isP[i][i+1] = true;
      }
    }

    // len >= 3
    for (int k = 3; k <= n; k++) {
      for (int i = 0, j = k - 1; j < n; i++, j++) {
        if (s[i] == s[j] && isP[i+1][j-1]) {
          isP[i][j]= true;
        }

        if (isP[i][j]) 
          dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + 1;
        else 
          dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
      }
    }
    return dp[0][n-1] + n;
      
  }
};

int main() {
  Solution s;
  string S = "abc";
  cout << s.countSubstrings(S) << endl;

}

