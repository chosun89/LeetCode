#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
      int sum = 0;

      for (auto a : A) {
        sum += a;
      }

      if (sum % 3 != 0) return false;

      int curr = 0;
      bool found1 = false;
      bool found2 = false;

      for (int i = 0; i < A.size(); i++) {
        curr += A[i];
        if (curr == sum / 3 && !found1) {
          found1 = true;
        }
        else if (curr == 2*sum/3 && !found2 && found1) {
          found2 = true;
        }

        if (found1 && found2) {
            return true;
        }
      }

      return false;
    }
};

int main() {
  Solution s;
  // vector<int> A = {3,3,6,5,-2,2,5,1,-9,4}; // 1
  vector<int> A = { 0,2,1,-6,6,7,9,-1,2,0,1}; // 0
  //vector<int>A = {6,1,1,13,-1,0,-10,20}; // 0
  cout << s.canThreePartsEqualSum(A) << endl;

}

