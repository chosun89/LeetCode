#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int inf = 0x3f3f3f3f;
    int minScoreTriangulation(vector<int>& A) {
      int n = A.size();

      int dp[n+1][n+1];
      for (int gap = 0; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
          if (j < i + 2) 
            dp[i][j] = 0;
          else {
            dp[i][j] = inf;
            for (int k = i + 1; k < j; k++) {
              int prod = dp[i][k] + dp[k][j] + A[i]*A[k]*A[j];
              if (prod < dp[i][j])
                dp[i][j] = prod;
            }
          }
        }
      }
      return dp[0][n-1];
    }
};

int main() {
  Solution s;
  vector<int> A = { 1,2,3 };
  cout << s.minScoreTriangulation(A) << endl;

}

