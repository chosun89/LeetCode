#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    // num -> indices
    unordered_map<int, vector<int> > mp;
    Solution(vector<int> nums) {

      for (int i = 0; i < nums.size(); i++) {
        mp[ nums[i] ].push_back(i);
      }
    }
    
    int pick(int target) {
      srand(time(0));
      return mp[target][ rand() % mp[target].size() ];
    }
};

int main() {
  Solution s();

}

