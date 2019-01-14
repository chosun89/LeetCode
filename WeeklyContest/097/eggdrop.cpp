#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int binom (int mid, int n, int k) {
      
      int res = 1;
      int sum = 0;
      for (int i = 1; i <= n; i++) {
        res *= (float)mid + 1 - i;
        res /= (float)(i);
        sum += res;

        if (res > k) break;
      }

      return (int)sum;
    }

    int superEggDrop(int N, int K) {
      int r = K;
      int l = 0;
      int mid;

      while (r - l > 1) {
        mid = l + (r - l) / 2;

        if (binom (mid, N, K) < K) l = mid;
        else r = mid;
      }

      return l + 1;
    }
};

int main() {
  Solution s;
  cout << s.superEggDrop(3, 14) << endl;

}

