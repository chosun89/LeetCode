#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int n = nums.size();
      int res = 0;
      int prod = 1;
      for (int i = 0, j = 0; j < n; j++) {
        prod *= nums[j];
        while (i <= j && prod >= k) {
          prod /= nums[i];
          i++;
        }
        res += j - i + 1;
      }

      return res;
    }
			
};

int main() {
  vector <int> nums = { 10, 5, 2, 6};
  int k = 100;
  //vector <int> nums = {10, 0};
  Solution sol;
  cout << sol.numSubarrayProductLessThanK(nums,k) << endl;

}

