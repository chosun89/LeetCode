#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
 
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
      int n = pairs.size();
      vector<int>dp(n + 1,1);
      sort(pairs.begin(), pairs.end());

      for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
          if (pairs[j][1] < pairs[i][0] && dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
          }
        }
      }
      return dp[n- 1];
    }
};

int main() {
  Solution s;
  vector< vector<int> > pairs = { {3,4}, {1,2}, {2,3} };
  cout << s.findLongestChain(pairs) << endl;

}

