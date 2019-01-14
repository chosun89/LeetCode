#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        int res = 0;
        int cont = 1;
        for (int i = 0 ; i < n - 1; i++) {
            if (nums[i + 1] > nums[i]) {
               cont++; 
            }
            else {
                cont = 0;
            }
            res = max(res, cont);
            
        }
        return res;
    }
};

int main() {
  vector<int> nums = { 1,3,5,4,7};
  Solution s;
  cout << s.findLengthOfLCIS(nums) << endl;

}

