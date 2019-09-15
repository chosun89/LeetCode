#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {

      int index, val;
      int sum = 0;
      vector<int> res;

      for (int i = 0; i < A.size(); i++) {
        if (A[i] % 2 == 0)
          sum += A[i];
      }

      for(auto p : queries) {
        index = p[1];
        val = p[0];
        bool was = false;

        if (A[index] % 2 == 0)
          was = true;

        A[index] += val;

        if(A[index] % 2 == 0) {
          if (was) { // it is already in our sum, only add val
            sum += val;
          }
          else {
            sum += A[index];
          }
        }
        else {
          if (was) {
            sum -= (A[index] - val);
          }
        }

        // cout << sum << endl;
        res.pb(sum);
      }
      return res;
    }
};

int main() {
  Solution S;
  vector<int> res;
  vector<vector<int>> q = { {1,0}, {-3,1}, {-4,0}, {2,3}};
  vector<int> A = {1,2,3,4};
  res = S.sumEvenAfterQueries(A, q);
  for(auto a : res) cout << a << endl;


}

