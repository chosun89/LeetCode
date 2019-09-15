#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool queryString(string S, int N) {
      
      for (int i = 1; i <= N; i++) {

        int n = i;
        string find = "";
        while(n) {
          if (n & 1) {
            find += "1";
          }
          else {
            find += "0";
          }
          n >>= 1;
        }
        reverse(find.begin(), find.end());
        

        if (S.find(find) == string::npos) {
          return false;
        }
      }
      return true;
    }
};

int main() {
  Solution s;
  string S = "0110";
  int N = 3;
  cout << s. queryString(S, N) << endl;

}

