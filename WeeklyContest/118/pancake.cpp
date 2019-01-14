#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    void flip(vector<int>& B, int mi) {
      for (int i = 0, j = mi; i < (mi+1)/2; i++, j--) {
        int temp = B[i];
        B[i] = B[j];
        B[j] = temp;
      }
      return;
    }
    vector<int> pancakeSort(vector<int>& A) {

      int n = A.size();
      vector<int> B = A;
      vector<int> res;

      for (int curr = n; curr > 1; curr--) {
        int mi = 0;
        for (int i = 0; i < curr; i++) {
          if (B[i] > B[mi]) {
            mi = i;
          }
        }

        if (mi != curr - 1) {
          flip(B, mi);
          flip(B, curr-1);
          res.pb(mi + 1);
          res.pb(curr);
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> A = {3,2,4,1};
  vector<int> res = s.pancakeSort(A);
  for (auto a : res) cout << a << " ";

}

