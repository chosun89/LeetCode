#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
      int n = A.size();
      int i = 0, j = 0;

      int maxi = 0;
      while (i < n) {
        if (A[i] == 0) {
          K--;
          if (K < 0) {
            if (A[j] == 0) {
              j++;
            } else {
              while(A[j] == 1) {
                j++;
              }
              j++;
            }
          }
        }      
        maxi = max(i - j + 1, maxi);
        i++;
      }
      return maxi;
    }
};

int main() {
  Solution s;
  vector<int> A = { 1,1,1,0,0,0,1,1,1,1,0 };
  int K = 2;
  cout << s.longestOnes(A,K) << endl;

}

