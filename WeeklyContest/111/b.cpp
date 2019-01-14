#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
      int n = A[0].size();
      int res = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < A.size() - 1; j++) {
          if (A[j][i] > A[j+1][i]) {
            res++;
            break;
          }
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<string> A = {"cba", "daf", "ghi" };
  cout << s.minDeletionSize(A) << endl;
}

