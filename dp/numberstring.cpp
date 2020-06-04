#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int mod = 1e9 + 7;

int numPermsDISequence(string S) {
  int n = S.size()+1;
  // number of valid DI seq of perm length i ending with int j
  int dp[n+1][n+1] = {}; 
  dp[1][1] = 1; // {1} == only one valid way
    
  // iterate over length n permutations
  for (int i = 2; i <= n; i++) {
    // iterate over all possible last digits (ie [1, i])
    for (int j = 1; j <= i; j++) {
      if (S[i - 2] == 'D') {
        // to make the current seq decreasing ending with j,
        // go to the previous permutation and add all
        // the ways it could end on a number greater
        // than or equal to j ( (i-1) - (j-1) == [j, i-1] )
        dp[i][j] = (dp[i][j-1] + (dp[i-1][i-1] - dp[i-1][j-1]) % mod) % mod;
      } 
      else if (S[i - 2] == 'I') {
        // if the seq is incrs ending with i, 
        // go to prev perm and add all the ways
        // it could end on [1, j-1]
        dp[i][j] = (dp[i][j-1] + dp[i-1][j-1]) % mod;
      }
    }
  }
  return (dp[n][n] + mod) % mod;
}

int main() {

}

