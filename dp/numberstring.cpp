#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int numPermsDISequence(string S) {
  int n = S.size()+1;
  int dp[n+1][n+1] = {};
  dp[1][1] = 1;
  int mod = 1e9 + 7;
    
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      if (S[i - 2] == 'D') {
        dp[i][j] = (dp[i][j-1] + (dp[i-1][i-1] - dp[i-1][j-1]) % mod) % mod;
      } 
      else if (S[i - 2] == 'I') {
        dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
      }
    }
        
  }
  return (dp[n][n] + mod ) % mod;
}

int main() {

}

