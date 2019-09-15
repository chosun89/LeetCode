#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
      int n = arr.size();
      vector<int> f(n,0);
      vector<int> b(n,0);

      int sum = arr[0];
      int maxi = arr[0];
      f[0] = arr[0];
      for (int i = 1; i < n; i++) {
        sum = max(arr[i], sum + arr[i]);
        maxi = max(sum, maxi);
        f[i] = sum;
      }

      b[n-1] = maxi = sum = arr[n-1];
      for (int i = n - 2; i >= 0; i--) {
        sum = max(arr[i], sum + arr[i]);
        maxi = max(sum, maxi);
        b[i] = sum;
      }

      int res = maxi;
      for (int i = 1; i < n-1; i++) {
        res = max(res, f[i-1] + b[i+1]);
      }
      return res;
    }
};

int main() {

  Solution s;
  vector<int> arr = {1,-2,-2,3};
  cout << s.maximumSum(arr) << endl;

}

