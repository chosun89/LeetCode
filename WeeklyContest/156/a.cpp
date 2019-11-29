#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int,int> mp;

      for (auto& a : arr) {
        mp[a] = mp[a] + 1;
      }

      set<int> st;
      for (auto it = mp.begin(); it != mp.end(); it++){
        if (st.find(it->second) == st.end())
          st.insert(it->second);
        else return false;
      }
      return true;
    }
};

int main() {

  Solution s;
  vector<int> arr = {1,2};
  cout << s.uniqueOccurrences(arr) << endl;

}

