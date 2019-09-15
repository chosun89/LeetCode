#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
using ull = unsigned long long;

class Solution {
public:
    string smallestGoodBase(string str) {
      ull n = stoll(str);

      for (int m = log2(n); m >= 2; m--) {
        int b = pow (n, 1.0/m);
        ull sum = 1;
        ull prod = 1;
        for (int i = 0; i < m; i++) {
          sum += (prod *= b);
        }
        if ( sum == n ) return to_string(b);
      }

      return to_string(n-1);
    }
};

int main() {
  Solution s;
  //string str = "1000000000000000000";
  //string str = "13";
  //string str = "14919921443713777"; // 496
  //string str = "16035713712910627"; // 502
  string str = "35417244247309081"; // 117
  cout << s.smallestGoodBase(str) << endl;

}

