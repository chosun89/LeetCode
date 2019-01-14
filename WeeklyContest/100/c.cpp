#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

const int maxn = 5e4 + 1;
int dp[maxn][maxn];

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
      int n = A.size();
      unordered_map<int,int> mp;
      memset(dp, 0, sizeof(dp));

      dp[0][0] = A[0];
      mp[ A[0] ]++;
      for (int i = 1; i < n; i++) {
        mp[A[i]]++;
        dp[0][i] = dp[0][i - 1] | A[i];
        mp[ dp[0][i] ]++;
      }

      for (int len = 2; len <= n; len++) {
        for (int i = 1, j = i + len - 1; j < n; j++, i++) {
          dp[i][j] = dp[i - 1] - A[i-1] + (a & dp
        }
      }
      
      return 9;
    }
};

int main() {

}

