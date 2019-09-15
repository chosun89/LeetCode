#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {

      vector<int> res = {a,b,c};
      sort(res.begin(), res.end());
      a = res[0];
      b = res[1];
      c = res[2];

      int mini = 0;
      int maxi = 0;

      if(c - b - 1 > 0 ) {
        mini++;
        maxi += (c - b - 1);
      }

      if (b - a - 1 > 0) {
        mini++;
        maxi += (b - a - 1);
      }

      if(c - a == 2 || b - a == 2) {
        mini = 1;
      }

      return {mini, maxi};
        
    }
};

int main() {
  Solution S;
  vector<int> res = S.numMovesStones(1,3,5);
  cout << res[0] << " " << res[1] << endl;

}

