#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
  int numSpecialEquivGroups(vector<string>& A) {
    int n = A.size();
    int len = A[0].size();
    set< pair < set<char>, set<char> > > res;

    for (int j = 0; j < n; j++) {
      string s = A[j];
      set<char> even;
      set<char> odd;
      for (int i = 0; i < len; i+=2) {
        even.insert(s[i]);
        if (i + 1 < len) odd.insert(s[i + 1]);
      }
      res.insert({even, odd});
    }

    
    return res.size();
  }
};

int main() {
  Solution s;
  //vector<string> A = { "aa","bb","ab","ba" };
  //vector<string> A = { "a","b","c","a","c","c" };
  vector <string> A = {"abcd","cdab","adcb","cbad"};
  cout << s.numSpecialEquivGroups(A) << endl;


}

