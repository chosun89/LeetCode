#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
      vector<int> mod(K, 0);
      int sum = 0, res = 0;
      for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        mod[(sum + K) % K]++;
      }

      for (int i = 0; i < mod.size(); i++) {
        if (mod[i]) {
          res += mod[i]*(mod[i]-1)/2;
        }
      }

      return res += mod[0];
    }

};

int main() {
  Solution s; 
  vector<int> A = {4,5,0,-2,-3,1};
  cout << s.subarraysDivByK(A, 5) << endl;
}

