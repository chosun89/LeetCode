#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
      vector<int> mp(26,10000);

      for (string str : A) {
        vector<int> temp(26,0);
        for (int i = 0; i < str.size(); i++) {
          temp[str[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
          if (mp[i] > temp[i]) {
            mp[i] = temp[i];
          }
        }
      }

      //for (auto a : mp) cout << a << " ";

      vector<string> res;

      for (int i = 0; i < 26; i++) {
          string a = "";
          a = i + 'a';
        for (int j = 0; j < mp[i]; j++) {
          res.pb(a);
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<string> A = { "bella", "label", "roller" };
  vector<string> res = s.commonChars(A);
  for(auto a : res) cout << a << " ";

}

