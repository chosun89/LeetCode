#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:

    bool uppercaserem(string str) {
      for (int i = 0; i < str.size(); i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
          return true;
        }
      }
      return false;
    }

    vector<bool> camelMatch(vector<string>& queries, string pattern) {

      vector<string> subpatterns;
      vector<bool> res;

      for(int i = 0; i < pattern.size(); i++) {
        if(pattern[i] >= 'A' && pattern[i] <= 'Z') {
          int j = i + 1;

          while (j < pattern.size() && pattern[j] >= 'a' && pattern[j] <= 'z') {
            j++;
          }

          subpatterns.pb(pattern.substr(i,j-i));
        }
      }


      for(int i = 0; i < queries.size(); i++) {
        string str = queries[i];

        int j = 0;
        for (; j < subpatterns.size(); j++) {
          string camel = subpatterns[j];
          int idx = str.find(camel);

          if(idx != string::npos) {
            str = str.substr(idx+camel.size());
          }

          else {
            res.pb(false);
            break;
          }
        }
        if(j == subpatterns.size()) {
          cout << str << endl;
          if(uppercaserem(str)) {
            res.pb(false);
          }
          else res.pb(true);
        }
      }
      return res;
    }
};



int main() {
Solution s;
vector<string> queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
string pattern = "FB";
vector<bool> res = s.camelMatch(queries, pattern);
for (auto b : res) cout << b << endl;

}

