#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int mod = 1e9 + 7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

      int sum = 0;
      int maxi = 0;
      int n = arr.size();
      bool length = true;
      for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum < 0) {
          sum = 0;
          length = false;
        }
        maxi = max(maxi, sum);
      }

      vector<int> copy(arr);
      arr.insert(arr.end(), copy.begin(), copy.end());

      int sum2 = 0;
      int maxi2 = 0;
      int n2 = arr.size();
      for (int i = 0; i < n2; i++) {
        sum2 = max(sum2 + arr[i], 0);
        maxi2 = max(maxi2, sum2);
      }

      if (length) {
        int res = maxi;
        for (int i = 0; i < k - 1; i++) {
          res = (res + maxi) % mod;
        }
        return res;
      }

      return (maxi < maxi2) ? maxi2 : maxi;
    }
};

int main() {

  Solution s;
  vector<int> arr = {1,2};
  int k = 3;
  cout << s.kConcatenationMaxSum(arr,k) << endl;

}

