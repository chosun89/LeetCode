#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    int surfaceArea(vector<vector<int>>& grid) {
      int n = grid.size();
      long sum = 0;
      FOR(i,0,n) { 
        FOR(j,0,n) {
          if (grid[i][j]) {
            sum += (6 + (4 * (grid[i][j] - 1)));
          }
          FOR(k,0,4) {
            int mini = grid[i][j]; 
            int dx = i + dir[k][0];
            int dy = j + dir[k][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
              mini = min (mini, grid[dx][dy]);
              sum -= mini;
            }
          }
        }
      }
      return sum;
    }
};

int main() {
  Solution s;
  vector< vector<int> > grid = { {1,1,1}, {1,0,1}, {1,1,1} };
  cout << s.surfaceArea(grid) << endl;
}

