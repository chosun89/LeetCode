#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        vector<int> counter(n + 1,0);
           
        for (int i = 0; i < n; i++) {
            counter[ nums[i] ] ++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (counter[i] == 1) continue;
            res.push_back(i);
        }
        for (auto a : res) cout << a << endl;
        return res;
    }
};

int main() {
  Solution s;
  vector<int> nums = { 1, 2, 2, 4};
  s.findErrorNums(nums);

}

