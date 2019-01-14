#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      int n = prices.size();

      int prev = 0;
      int dp0 = 0, dp1 = INT_MIN;
      for (int i = 0; i < n; i++) {
        dp0 = max (dp0, prices[i] + dp1);
        dp1 = max (dp1, prev - prices[i] - fee);
        prev = dp0;
      }
      return dp0;
    }
};

int main() {
  Solution sol;
  //vector<int> prices = {1, 3, 2,8,4,9}; // ans = 8
  vector<int> prices = {1,3,7,5,10,3}; // ans = 6
  int fee = 3;
  cout << sol.maxProfit(prices, fee) << endl;

}

