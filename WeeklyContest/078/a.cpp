#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
      unordered_map<string,int> mp;

      for (auto str : cpdomains) {
        parse(str,mp);
      }
      vector<string> res;
      for (auto p : mp) {
        res.pb(to_string(p.second) + " " + p.first);
      }
      return res;
    }

    void parse (string str, unordered_map<string,int>& mp ) {
      int i = 0;
      int count = 0;
      while (str[i] != ' ') {
        count = count*10 + (str[i] - '0');
        i++;
      }
      i++;
      string str2 = str.substr(i);
      mp[str2] += count;
      int r = str2.size() - 1;
      r--;
      while (r != -1) {
        if (str2[r] == '.') {
            cout << str2.substr(r+1) << endl;
            mp[str2.substr(r+1)] += count;
          }
        r--;
      }
    }
};

int main() {
  Solution s;
  //vector<string> A = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"}; 
  vector<string> A = { "9001 discuss.leetcode.com"};
  vector<string> res = s.subdomainVisits(A);
  for (auto s : res) cout << s << " ";


}

