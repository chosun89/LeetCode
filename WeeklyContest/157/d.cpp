#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    int countVowelPermutation(int n) {
      int a = 1, e = 1, i = 1, o = 1, u = 1;
      for (int i = 0; i < n; i++) {
        a = e + i;
        e = a + i + u;
        i = o;
        o = i;
        u = o + i;
      }

      return a + e + i + o + u;
    }
};

int main() {

}

