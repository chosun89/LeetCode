#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int clumsy(int N) {
      if (N == 1) return 1;
      if (N == 2) return 2;
      if (N == 3) return 3*2;

      int res = 0;

      int rounds = N / 4;
      int n = N;

      bool first = true;
      while (rounds-- >= 1) {
        if (first) {
          res += ((N*(N-1))/(N-2));
          res += (N-3);
          first = false;
        }
        else {
          res -= (N*(N-1)/(N-2));
          res += (N-3);
        }
        N -= 4;
      }

      if (n % 4 == 0) {
        return res;
      } 
      else if (n % 4 == 1) {
        return res  - 1;
      }
      else if (n % 4 == 2) {
        return res - 2;
      }
      else {
        return res - 6;
      }
    }
};

int main() {
  Solution s;
  int N = 2;
  cout << s.clumsy(N) << endl;

}

