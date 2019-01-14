#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {

      int n = A.size();
      int maxi = 0;

      sort(A.begin(), A.end());
      for (int i = 0; i < n-2; i++) {
        if ((A[i] + A[i+1]) <= A[i+2]) continue;
        else {
          if ( (A[i] + A[i+1] + A[i+2]) > maxi) {
            maxi = A[i] + A[i+1] + A[i+2];
          }
        }
      }

       return maxi; 
    }
};

int main() {
  Solution s;
  vector<int> A = {2,1,2};
  cout << s.largestPerimeter(A) << endl;


}

