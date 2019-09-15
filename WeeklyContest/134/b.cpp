#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

    void dfs(vector<vector<int>>& grid, pair<int,int> u, int c_color) {
      int r = u.first;
      int c = u.second;
      int n = grid.size();
      int m = grid[0].size();

      if(grid[r][c] == 0) return;

      grid[r][c] = 0;

      for (int i = 0; i < 4; i++) {
        int dr = r + dir[i][0];
        int dc = c + dir[i][1];

        if (dr >= 0 && dr < n && dc >= 0 && dc < m && grid[dr][dc] == c_color) {
          dfs(grid, {dr, dc}, c_color);
        }

      }
      return;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
      int b_color = color;
      int c_color = grid[r0][c0];
      int n = grid.size();
      int m = grid[0].size();

      dfs(grid, {r0, c0}, c_color);

      for (int i = 0; i < n; i++) {
        if (grid[i][0] == 0) {
          grid[i][0] = -1;
        }
      }
      for (int i = 0; i < n; i++) {
        if (grid[i][m-1] == 0) {
          grid[i][m-1] = -1;
        }
      }
      for (int j = 0; j < m; j++) {
        if (grid[0][j] == 0) {
          grid[0][j] = -1;
        }
      }
      for (int j = 0; j < m; j++) {
        if (grid[n - 1][j] == 0) {
          grid[n - 1][j] = -1;
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << grid[i][j] << " ";
        }
        cout << endl;
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] != 0 && grid[i][j] != -1) {
            for (int k = 0; k < 4; k++) {
              int dr = i + dir[k][0];
              int dc = j + dir[k][1];

              if (dr >= 0 && dr < n && dc >= 0 && dc < m && (grid[dr][dc] == 0)) {
                grid[dr][dc] = -1;
              }
            }
          }
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (grid[i][j] == 0) {
            grid[i][j] = c_color;
          }
          if (grid[i][j] == -1)
            grid[i][j] = b_color;
        }
      }

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << grid[i][j] << " ";
        }
        cout << endl;
      }
      
      return grid;
    }
};

int main() {
  Solution s; 
  vector<vector<int>> grid = {{1,2,1,2,1,2},{2,2,2,2,1,2},{1,2,2,2,1,2}};
  s.colorBorder(grid, 1,3,1);

}

