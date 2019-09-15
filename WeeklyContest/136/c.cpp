#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
      int n = A.size();
      vector<int> dp(n + 1, 0);
      for (int i = 0; i < n; i++) {

        int curmax = -1;
        for (int k = 1; k <= K && i - k + 1 >= 0; k++) {
          curmax = max(curmax, A[i - k + 1]);
          dp[i] = max(dp[i], dp[i - k] + curmax * k);

        }
      }

      return dp[n-1];
    }
};

int main() {

  Solution s;
  vector<int> A = { 1,15,7,9,2,5,10 };
  cout << s.maxSumAfterPartitioning(A, 3) << endl;

}

