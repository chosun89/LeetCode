#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {

      vector<int> res;
      int i = A.size() - 1;
      int carry = 0;

      while (K != 0 || i >= 0) {
        int sum = (K % 10 + carry);

        if (i >= 0) {
          sum = (sum + A[i]);
        }

        res.pb(sum % 10);
        carry = sum / 10;
        K /= 10;
        i--;
      }

      if (carry)
        res.pb(carry);

      for (int i = 0, j = res.size() - 1; i < res.size()/2; i++, j--) {
        int temp = res[i];
        res[i] = res[j];
        res[j] = temp;
      }

      return res;
        
    }
};

int main() {
  Solution S;
  vector<int> A = {0};
  int K = 3;
  vector<int> res = S.addToArrayForm(A, K);
  for(auto a : res) cout << a;
  cout << endl;

}

