#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int projectionArea(vector< vector<int >>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      int count = 0;
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++){
              if (grid[i][j]) count++;
          }
      }

      for (int i = 0; i < n; i++) {
          int maxi = grid[i][0];
          for (int j = 0; j < m; j++) {
              if (grid[i][j] > maxi) {
                  maxi = grid[i][j];
              }
          }
          count += maxi;
      }
      
      for (int j = 0; j < m; j++) {
          int maxi = grid[0][j];
          for (int i = 0; i < n; i++){
              if (grid[i][j] > maxi) {
                  maxi = grid[i][j];
              }
          }
          count += maxi;
      }
      return count;
  }
};

int main() {
  Solution sol;
  vector< vector<int> > v = {{1,1,1}, {1,0,1}, {1,1,1}};
  cout << sol.projectionArea(v) << endl;

}

