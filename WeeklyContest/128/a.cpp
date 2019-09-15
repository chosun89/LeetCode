#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
      if ( N == 0)
        return ~N;

      int count = ceil(log2(N));

      int mask = INT_MAX ;
      mask >>= (31 - count);

      return mask & (~N);

    }
};

int main() {
  Solution s;
  int N = 0;
  cout << s.bitwiseComplement(N) << endl;


}

