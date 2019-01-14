#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
      string numstr = to_string(N);
      int len = numstr.size();
      int digits = D.size();
      int res = 0;

      for (int i = 1; i < len; i++) {
        res += pow (digits, i);
      }

      for (int i = 0; i < len; i++) {
        bool same = false;
        for (string d : D) {
          if (d[0] < numstr[i]) {
            res += pow (digits, (len - ( i + 1 )));
          }
          else if (d[0] == numstr[i]) {
            same = true;
          }
        }
        if (!same) return res;
      }
      // the above lop returns true in all cases, 
      // meaning the digits can compose N, res + 1
      return res + 1; 
    }
};

int main() {
  Solution s;
  vector <string> D = {"1", "2", "9"};
  int N = 1900;
  cout << s.atMostNGivenDigitSet(D, N) << endl;
}

