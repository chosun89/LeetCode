#include <bits/stdc++.h>
#define pb push_back
using namespace std;

bool comp(string a, string b) {
  return a.size() < b.size();
}

class Solution {
public:
    // return true if a is pred of b
    bool ispred(string& a, string& b) {
      if (b.size() - a.size() != 1) return false;

      int n = a.size();
      for(int i = 0; i <= n; i++) {
        if (a == b.substr(0,i) + b.substr(i+1)) return true;
      }
      return false;
    }

    int longestStrChain(vector<string>& words) {
      sort(words.begin(), words.end(), comp);
      int n = words.size();
      vector<vector<bool>> cando(n, vector<bool>(n, false));
      vector<int> dp(n, 1);

      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          cando[i][j] = ispred(words[i], words[j]);
        }
      }

      int res = -1;
      for(int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          if (cando[j][i])
            dp[i] = max(dp[i] , dp[j] + 1);
            if(dp[i] > res) res = dp[i];

        }
      }

      return res;

    }
};

int main() {
  Solution s;
  vector<string> words = {"a","b","ba","bca","bda","bdca"};
  cout << s.longestStrChain(words) << endl;
  

}

