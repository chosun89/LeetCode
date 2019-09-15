#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

class Solution {
public:
    bool only(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (only(grid)) return 0;
        
        // x,y
        queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                  grid[i][j] = 3;
                  q.push({i,j});
                }
            }
        }
        int min = 0;

        while (!q.empty()) {
          int sz = q.size();

          for (int i = 0; i < sz; i++) {
            pair<int,int> top = q.front();

            for (int j = 0; j < 4; j++) {
              int row = top.first + dir[j][0];
              int col = top.second + dir[j][1];
              if (row < n && row >= 0 && col < m && col >= 0 && grid[row][col] == 1) {
                  cout << row << " " << col << endl;
                  grid[row][col] = 3;
                  q.push( {row, col} );
              }
            }
            q.pop();
          }
          min++;
        }

        for (int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
          if (grid[i][j] == 1) return -1;
        }
        return --min;
    }
};
int main() {
  Solution s;
  //vector<vector<int>> grid = { {2,1,1}, {1,1,0}, {0,1,1}};
  //vector<vector<int>> grid = { {2,1,1}, {0,1,1}, {1,0,1} };
  vector<vector<int>> grid = { {2,2}, {1,1}, {0,0},{2,0} };
  cout << s.orangesRotting(grid) << endl;

}

