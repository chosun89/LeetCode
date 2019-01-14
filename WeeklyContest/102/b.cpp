#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& tree) {
      unordered_map<int,int> mp; // type -> count;
      int n = tree.size();
      int res = 0;
      for (int i = 0, j = 0; j < n; j++) {
        mp[ tree[j] ]++;
        while (mp.size() > 2) {
          mp[tree[i]]--;
          if (mp[tree[i]] == 0) mp.erase(tree[i]);
          i++;
        }
        res = max(res, j - i + 1);
      }
      return res;
    }
};

int main() {

}

