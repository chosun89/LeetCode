#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
      int c1 = 0, n = A.size();
      for (auto a : A) {
        c1 += a;
      }

      if (c1 == 0) return {0,n-1}; // if no 1's present, return trivial partition
      if (c1 % 3 != 0) return {-1,-1}; // if num 1's is not multi of 3, return false
      int k = c1 / 3; // the number of 1's present in each partition
      int i, start, mid, end; // the start of each partition begins with 1

      for (i = 0; i < n; i++) {
        if (A[i] == 1) break;
      }
      start = i;

      c1 = 0;
      for (i = 0; i < n; i++) {
        c1 += A[i];
        if (c1 == k + 1) break;
      }
      mid = i;

      c1 = 0;
      for (i = 0; i < n; i++) {
        c1 += A[i];
        if (c1 == 2*k + 1) break;
      }
      end = i;
      
      while (end < n && A[start] == A[mid] && A[mid] == A[end]) {
        start++;
        mid++;
        end++;
      }

      if (end == n) return {start, mid+1};

      return {-1,-1};

    }
};

int main() {
  Solution s;
  vector<int> A = {1,0,1,1,0};
  vector<int> res = s.threeEqualParts(A);
  cout << res[0] << ", " << res[1] << endl;

}
