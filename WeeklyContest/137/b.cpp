#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {

      int n = S.size();
      while(n) {
        int i = 0;
        n = S.size();
        bool found = false;
        for (; i + 1 < n; i++) {
          if (S[i] == S[i+1]) {
            S = S.substr(0, i) + S.substr(i + 2);
            n = S.size();
            found = true;
            //cout << S << endl;
            break;
          }
        }
        if (!found)
          return S;
      }
        
      return S;
    }
};

int main() {
  Solution s;
  string S = "aaaaaa";
  cout << s.removeDuplicates(S) << endl;

}

