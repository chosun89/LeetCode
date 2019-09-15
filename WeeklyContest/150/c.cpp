#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:

  vector<vector<int>> dir = { {0,1}, {0,-1}, {1,0}, {-1,0} };
  int maxDistance(vector<vector<int>>& grid) {
    int N = grid.size();
    queue <pair<int,int>> q;
    vector<vector<int>> dp (N, vector<int>(N, -1));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == 1) {
          q.push({i,j});
          dp[i][j] = 0;
        }
      }
    }

    while(!q.empty()) {
      auto top = q.front();
      int r = top.first;
      int c = top.second;
      for (int i = 0; i < 4; i++) {
        int dr = r + dir[i][0];
        int dc = c + dir[i][1];

        if (dr < N && dr >= 0 && dc < N && dc >= 0 && dp[dr][dc] == -1) {
          dp[dr][dc] = dp[r][c] + 1;
          q.push({dr,dc});
        }
      }
      q.pop();
    }

    int maxi = -1;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        maxi = max(maxi, dp[i][j]);
      }
    }
    return maxi == 0 ? -1 : maxi;
  }
};

int main() {
  Solution s;
  vector<vector<int>> grid =  { {1,0,1},{0,0,0},{1,0,1} };
  cout << s.maxDistance(grid) << endl;

}

