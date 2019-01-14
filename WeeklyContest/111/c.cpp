#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
      int N = S.size();
      int l = 0, r = N;
      vector<int> res;
      for (int i = 0; i < N; i++) {
        if(S[i] == 'I') {
          res.pb(l);
          l++;
        }
        else {
          res.pb(r);
          r--;
        }
      }
      res.pb(l);
      return res;
    }
};

int main() {

  Solution s;
  auto res = s.diStringMatch("IDID");
  for ( int i : res ) cout << i << " ";

}

