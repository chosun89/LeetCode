#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int smallestRepunitDivByK(int K) {

      if (K%2 == 0) return -1;

      int mod = 0;
      int cnt = 1;
      long long ten = 1;

      while(true) {
        mod += (ten % K);
        mod %= K;
        if (mod == 0) return cnt;

        if (ten % K == 0 && mod != 0) return -1;

        cnt++;
        ten *= 10;
      }

       return -1; 
    }
};

int main() {
  Solution s;
  int K = (1e5) - 1;
  cout << s.smallestRepunitDivByK(K) << endl;

}

