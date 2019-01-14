#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
      vector<int> res;
      int n = A.size();
      int m = B.size();

      unsigned long sumA = 0;
      unsigned long sumB = 0;
      
      for (auto a : A) sumA += a;
      for (auto b : B) sumB += b;
      unsigned long tar = (sumA + sumB) / 2;

      //sort(A.begin(),A.end());
      //sort(B.begin(),B.end());

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          
          if ( (sumA - A[i] + B[j]) == tar && (sumB - B[j] + A[i]) == tar) {
            res.push_back(A[i]);
            res.pb(B[j]);
            return res;
          }
        }
      }

      return res;
    }
};

int main() {
  Solution s;
  vector<int> A = {1,2,5};
  vector<int> B = {2,4};
  vector <int> res = s.fairCandySwap(A,B);
  for (auto a : res) cout << a << " ";


}

