#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

vector<int> dir[4] = { {0,1}, {1,0}, {-1,0}, {0,-1} };
class Compare {
public:
  bool operator() (vector<int>& a, vector<int>& b) {
    return a[2] > b[2]; // this line reverses the max-heap order ie makes it min-heap
  }
};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
      if ( forest.size() == 0) return -1;
      int m = forest.size(); int n = forest[0].size();
      priority_queue< vector<int>, vector< vector<int> >, Compare > pq;

      FOR(i,0,m) FOR(j,0,n) {
        if (forest[i][j] > 1 ) pq.push( {i, j, forest[i][j]} );
      }

      int res = 0;
      vector<int> start(2,0);
      while (!pq.empty()) {
        auto next = pq.top();
        pq.pop();
        int steps = minsteps(forest, start, next, m, n);
        if (steps < 0 ) return -1;
        res += steps;
        start[0] = next[0];
        start[1] = next[1];
      }
      return res;
    }

private:
    int minsteps(vector<vector<int>>&forest, vector<int>& start, vector<int>& next, int m, int n) {
      queue< vector<int> > q;
      q.push( {start[0], start[1]} );
      vector< vector<bool> > visit (m, vector<bool>(n,false));
      visit[start[0]][start[1]] = true;
      int steps = 0;
      while (!q.empty()) {
        int k = q.size();
        FOR(j,0,k) {
          auto top = q.front();
          q.pop();
          //cout << next[-1] << " " << next[1] << endl;
          if (top[0] == next[0] && top[1] == next[1]) return steps;
          FOR(i,0,4) {
            int dr = top[0] + dir[i][0];
            int dc = top[1] + dir[i][1];

            if (dr >= 0 && dr < m && dc >= 0 && dc < n && !visit[dr][dc] && forest[dr][dc]) {
              q.push( {dr,dc} );
              visit[dr][dc] = true;
            }
          }
        }
        steps++;
      }
      return -1;
    }
};

int main() {
  Solution s;
  vector<vector<int>> forest = { {2,3,4}, {0,0,5},{8,7,6} };
  cout << s.cutOffTree(forest) << endl;
}

