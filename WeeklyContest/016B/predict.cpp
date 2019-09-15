#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      int N = nums.size();
      int sum = 0;
      for (auto s : nums) sum += s;
      vector< vector<int> > dp (N, vector<int> (N, 0));
      for (int i = 0; i < N; i++)
        dp[i][i] = nums[i];

      FOR(len,1,N) {
        for (int i = 0, j = i + len; j < N; i++, j++) {
          dp[i][j] = max (nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
        }
      }
      return (dp[0][N-1] >= 0);
    }
};

int main() {
  //vector<int> res = {10, 1, 3, 5, 11};
  vector<int> res = {1,5,2};
  Solution s;
  cout << s.PredictTheWinner(res) << endl;
}

