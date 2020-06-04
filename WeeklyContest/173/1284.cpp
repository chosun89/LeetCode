#include <bits/stdc++.h>
#define matrix vector<vector<int>>
using namespace std;
int dir[5] = { 0, 1, 0, -1, 0};
class Solution {
public:
  unordered_map<int, int> mp; // matrix -> # of steps
  int rows, cols;

  int tobits(matrix& mat) {
    int bits = 0;
    for(int r=0;r<rows;r++){
      for(int c=0;c<cols;c++){
          bits <<= 1;
          bits |= mat[r][c];
      }
    }
    return bits;
  }

  int flip(int r, int c, int bits) {
    int cell = (rows*cols-1) - (r*cols+c);
    bits ^= (1<<cell);
    for(int i = 0; i < 4; i++) {
      int dr = r + dir[i];
      int dc = c + dir[i+1];
      if(dr>=0&&dr<rows&&dc>=0&&dc<cols) {
        int cell = (rows*cols-1) - (dr*cols+dc);
        bits ^= (1<<cell);
      }
    }
    return bits;
  }
  
  int minFlips(vector<vector<int>>& mat) {
    this->rows = mat.size();
    this->cols = mat[0].size();
    queue<int> q;
    int first = tobits(mat);
    mp[first] = 1;
    q.push(first);
    int dist = 0;
    while(!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        int top = q.front();
        if(top == 0) return dist;
        q.pop();
        for(int r=0;r<rows;r++)for(int c=0;c<cols;c++) {
          int flipped = flip(r,c,top);
          int& neigh = mp[flipped];
          if (neigh == 0) { // not visited state
            q.push(flipped);
            neigh = 1;
          }
        }
      }
      dist++;
    }
    return dist;
  }
};

int main() {
}
