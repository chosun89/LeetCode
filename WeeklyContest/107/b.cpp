#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string S) {

      int onesC = 0, flipC = 0;

      for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') {

          if (onesC == 0) continue;

          else flipC++;

        } else onesC++;

        if (flipC > onesC)
          flipC = onesC;
      }
      return flipC;
        
    }
};

int main() {
  Solution s;
  string two = "100000001010000";
  string three = "1111001110";
  cout << s.minFlipsMonoIncr(three) << endl;

}

