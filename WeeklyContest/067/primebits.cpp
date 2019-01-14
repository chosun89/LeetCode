#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
const int maxn = 30;
    int countPrimeSetBits(int L, int R) {
      vector<int> prime(maxn + 1, 1);
      prime[0] = 0;
      prime[1] = 0;
      for (int i = 4; i <= maxn; i+=2) {
        prime[i] = 0;
      }

      for (int i = 3; i <= maxn; i++) {
        if (prime[i] == 1) {
          for (int j = i*i; j <= maxn; j+=i) {
            prime[j] = 0;
          }
        }
      }
      for(auto a : prime) cout << a << " ";

      int res = 0;
      for (int i = L; i <= R; i++) {
        int k = i;
        int count = 0;
        for (int j = 0; j < 32; j++, k >>= 1) {
          if (k & 1) {
            count++;
          }
        }
        if (prime[count]) res++;
      }
      return res;
        
    }
};

int main() {
  Solution s;
  cout << s.countPrimeSetBits(289051, 294301) << endl;


}

