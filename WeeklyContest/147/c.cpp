#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int get_rect(int r1, int c1, int r2, int c2, vector<vector<int>>& pre) {
        return pre[r1][c1] - pre[r2][c1] - pre[r1][c2] + pre[r2][c2];
    }

    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size() ? grid[0].size() : 0;
        vector<vector<int>> pre (R + 1, vector<int>(C + 1, 0));

        // construct prefix sum matrix
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + grid[i][j];
            }
        }

        bool found = true;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid[i][j] == 1)
                    found = false;
            }
        }

        if (found)
            return 0;

        int best = 1;
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                for (int s = best + 1; r + s <= R && c + s <= C; s++) {
                    if (get_rect(r + s, c + s, r, c, pre) - get_rect(r + s - 1, c + s - 1, r + 1, c + 1, pre) == 4 * (s - 1))
                        best = s;
                }
            }
        }
        return best * best;
    }

};

int main() {
    Solution s;
}

