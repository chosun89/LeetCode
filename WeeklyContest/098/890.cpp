#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
  vector<string> findAndReplacePattern(vector<string>& words, string pat) {
    vector<string> res;
     for (auto w : words) {
       set<int> in[26];
       set<int> out[26];
       FOR(i,0,w.size()) {
         in[ w[i] - 'a' ].insert(pat[i] - 'a');
         out[pat[i] - 'a'].insert(w[i] - 'a');
       }
       bool good = true;
       FOR(i,0,26) {
         if (in[i].size() > 1 || out[i].size() > 1) {
           good = false;
           break;
         }
       }
       if (good) res.pb(w); 
      }
    return res;    
  }
};

int main() {


}

