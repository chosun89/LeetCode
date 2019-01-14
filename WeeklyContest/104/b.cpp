#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
      int n = A.size();
      vector<int> left (n);
      vector<int> right(n);

      left[0] = A[0];
      for (int i = 1; i < A.size(); i++) {
        left[i] = max (left[i-1], A[i]);
      }

      right[n-1] = A[n-1];
      for (int i = n-2; i >= 0; i--) {
        right[i] = min (right[i+1], A[i]);
      }

      for (int i = 0; i < n-1; i++) {
        if (left[i] < right[i+1])
          return i +1;
      }
      return 1;
    }
};

int main() {
  Solution s;
  //vector<int> A = {5,0,3,8,6}; // left = 3 {5,0,3}, {8,6}
  vector<int> A = {6,0,8,30,37,6,75,98,39,90,63,74,52,92,64};
  cout << s.partitionDisjoint(A) << endl;

}

