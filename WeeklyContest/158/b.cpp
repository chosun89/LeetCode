#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
      vector<vector<int>> res;

      set<vector<int>> st;
      for (auto q : queens) st.insert(q);

      for (auto d : dir) {
        for (int j = 1; j <= 8; j++) {
          int x = j * d[0] + k[0];
          int y = j * d[1] + k[1];
          vector<int> p = {x, y};
          if (st.find(p) != st.end()){
            res.push_back(p);
            break;
          }
        }
      }
      return res;
    }
};

int main() {

}
