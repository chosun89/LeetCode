#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

      sort(arr.begin(), arr.end());
      int n = arr.size();
      int mini = 1e9;
      for (int i = 0; i < n - 1; i++) {
        mini = min (mini, arr[i+1] - arr[i]);
      }

      vector<vector<int>> res;
      for (int i = 0; i < n - 1; i++) {
        if (arr[i+1] - arr[i] == mini)
          res.push_back({arr[i],arr[i+1]});
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> arr = {3,8,-10,23,19,-4,-14,27};

  auto res = s.minimumAbsDifference(arr);
  for (auto r : res) cout << r[0] << " " << r[1] << endl;

}

