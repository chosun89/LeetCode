#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> alp (26);
      FOR(i,0,S.size()) {
        alp[ S[i] - 'a'] = i;
      }

      int st = 0;
      int ls = 0;
      vector<int> res;
      FOR(i,0,S.size()) {
        ls = max (ls, alp [ S[i] - 'a']);
        if (i == ls) {
          res.pb(ls - st + 1);
        }
        st = ls + 1;
      }
      return res;
        
    }
};

int main() {

}

