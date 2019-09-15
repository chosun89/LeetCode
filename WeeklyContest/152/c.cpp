#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<bool> res;
    map<string,int> mp;
    for (auto& q : queries) {
      int odd = 0;
      vector<int> chars(26,0);

      string sub = s.substr(q[0], q[1] - q[0] + 1);

      if (mp.find(sub) == mp.end()) {
        for (int i = q[0]; i <= q[1]; i++) {
          chars[s[i]-'a']++;
        }

        for (int i = 0; i < 26; i++) {
          if (chars[i] & 1)
            odd++;
        }
        mp[sub] = odd;
      }

      else {
        odd = mp[sub];
      }

      if ((odd - 2*q[2]) > 1)
        res.pb(false);
      else res.pb(true);
    }

    return res;
  }
};

int main() {
  Solution s;

  string str = "abcda";
  vector<vector<int>> q = { {3,3,0}, {1,2,0}, {0,3,1}, {0,3,2}, {0,4,1} };
  vector<bool> res = s.canMakePaliQueries(str, q);
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
}

