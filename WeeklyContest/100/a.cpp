#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        
        if (isdec(A) || isinc(A)) {
          return true;
        }

        return false;
    }

    bool isdec(vector<int>&A) {
      int n = A.size();
      FOR(i,0,n - 1) {
        if (A[i] <= A[i + 1]) continue;
        else return false;
      }
      return true;
    }

    bool isinc(vector<int>&A) {
      int n = A.size();
      FOR(i,0,n - 1) {
        if (A[i] >= A[i + 1]) continue;
        else return false;
      }
      return true;
    }
};

int main() {
  Solution s;
  vector<int> A = {1,1,1,1};
  cout << s.isMonotonic(A);

}

