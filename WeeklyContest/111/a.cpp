#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
      int n = A.size();
      vector<int> res;
      if (n < 3) return false;
      bool pos = true;

      for (int i = 0; i < n-1; i++) {
        int diff = A[i+1] - A[i];
        res.pb(diff);
    }

    if (res[0] < 0) return false;
    bool ok = true;
    for (int i = 0; i < res.size(); i++) {
      if (res[i] == 0) return false;
      if (pos) {
        if (ok && res[i] < 0) {
          ok = false;
          pos = false;
          continue;
        }
      } else {
        if (res[i] > 0) return false;
        }
    }
    if (pos) return false;
    return true;
    }
};

int main() {
  Solution s;
  vector<int> A = { 1,2,3,4,5 };
  cout << s.validMountainArray(A) << endl;

}

