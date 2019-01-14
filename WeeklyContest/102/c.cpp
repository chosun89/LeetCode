#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
class Solution {
public:
    int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
      int res = 0;
      vector<int>dp;
      FOR(i,0,A.size()) {
        res += A[i];
        dp.pb(A[i]);
      }
      FOR(i,0,A.size()-1) {
      }

      while (dp.size() >= 1) {
        vector<int> temp;
        if (dp.size() == 1) return (res + dp[0]) % mod;
        //for (auto a : dp) cout << a << " ";
        // cout << endl;
        if (dp.size() % 2 == 0) {
          for (int i = 0; i < dp.size() - 1; i++) {
            if (dp[i] < dp[i+1]) {
              res += dp[i];
              temp.pb(dp[i]);
            }
            else {
              res += dp[i+1];
              temp.pb(dp[i+1]);
            }
          }
        }
        else {
          temp.pb(dp[0]);
          for (int i = 1; i < dp.size() - 1; i++) {
            if (dp[i] < dp[i+1]) {
              res += dp[i];
              temp.pb(dp[i]);
            }
            else {
              res += dp[i+1];
              temp.pb(dp[i+1]);
            }
          }
        }
        res %= mod;
        dp = temp;
      }
      return (res);
    }
};

int main() {
  Solution s;
  //vector<int> A = {3,1,2,4};
  vector<int> A = { 59, 91 };
  cout << s.sumSubarrayMins(A) << endl;

}

