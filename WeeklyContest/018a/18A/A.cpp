#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        
        
        string row1 = "QWERTYUIOPqwertyuiop";
        string row2 = "ASDFGHJKLasdfghjkl";
        string row3 = "ZXCVBNMzxcvbnm";
        unordered_map<char, int> m;
        vector<string> res;

        for (char c : row1) m[c] = 1;
        for (char c : row2) m[c] = 2;
        for (char c : row3) m[c] = 3;

        for (auto w : words) {
          int n = w.size();
          int row = m[ w[0] ];
          bool add = true;
          FOR(i,1,n) {
            if (m[ w[i] ] != row) {
              add = false;
              break;
            }
          }
          if (add) res.pb(w);
        }
        
        return res;
    }
};

int main() {
  vector<string> A = {"Hello", "Alaska"};
  Solution s;
  vector<string> res = s.findWords(A);
  for (auto s : res) cout << s << " ";

}

