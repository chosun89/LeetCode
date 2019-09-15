#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    
    int brokenCalc(int X, int Y) {
      int res = 0;
      while (Y > X) {
        Y = Y % 2 > 0 ? Y + 1 : Y / 2;
        res++;
      }

      return res + X - Y;
    }
};

int main() {
  Solution s;
  cout << s.brokenCalc(2, 9) << endl;

}

