#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
      vector<int> res;
      vector<int> e;
      vector<int> o;
			for (int i = 0; i < A.size(); i++) {
				if (A[i] % 2 == 0) {
          e.pb(A[i]);
        }
        else o.pb(A[i]);
      }
      res.insert(res.end(), e.begin(), e.end());
      res.insert(res.end(), o.begin(), o.end());
      return res;
    }
};

int main() {
  vector< int > ab = {3,1,5,2,7,4,6};
  Solution s;
  vector<int> res = s.sortArrayByParity(ab);
  for (auto a : res) cout << a << " ";

}

