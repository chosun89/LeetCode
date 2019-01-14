#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

const int maxfib = 33;
int fib [maxfib];
class Solution {
public:
    int findIntegers(int num) {
      fib[0] = 0;
      fib[1] = 1;
      for (int i = 2; i < maxfib; i++) 
        fib[i] = fib[i-1] + fib[i-2];

      int k = 31, pre = 0, res = 0;
      while (k) {
        if (num & (1 << k)) {
          res += fib[k];
          pre = 1;
          if (pre ) return res;
        }
        else pre = 0;
        k--;
      }
      return res;
    }
};

int main() {
  Solution s;
  cout << s.findIntegers(10)<< endl;

}

