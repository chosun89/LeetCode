#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {

      int n = s.size();
      vector<int> dp;
      for (int i = 0; i < n; i++) {
        dp.push_back(abs(s[i] - t[i]));
      }

      vector<int> pre (n + 1, 0);
      for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + dp[i];
      }

      return 0;
    }
};

int main() {
  Solution s;
  string st = "abcd";
  string t = "cdef";
  int m = 3;
	st = "krpgjbjjznpzdfy";
  t = "nxargkbydxmsgby";
  m = 14;
  cout << s.equalSubstring(st,t,m) << endl;

}

