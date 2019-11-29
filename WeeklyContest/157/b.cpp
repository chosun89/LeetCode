#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
      map<int, int> mp;
      int res = 0;
      for (auto& c : arr) {
        mp[c] = mp[c - diff] + 1;
        res = max(mp[c], res);
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> arr = {1,5,7,8,5,3,4,2,1 };
	int diff = -2;
  cout << s.longestSubsequence(arr, diff) << endl;
}

