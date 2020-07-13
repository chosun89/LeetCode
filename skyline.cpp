#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

const int mn = 10000 + 1;
int seg[mn << 1];

class Solution {
public:

    int n; // number of unique x pos

    void buildtree() {
      memset(seg, 0, sizeof(seg));
    }

    void modify(int l, int r, int height) {
      l += this->n; r += this->n;
      for (; l < r; l >>= 1, r >>= 1) {
        if (l&1) { seg[l] = max(height, seg[l]); l++; }
        if (r&1) { r--; seg[r] = max(height, seg[r]); }
      }
    }

    int query(int p) {
      int maxi = INT_MIN;
      for (p += this->n; p > 0; p>>=1) {
        maxi = max(maxi, seg[p]);
        // cout << maxi << " ";
      }
      // cout << endl;
      return maxi;
    }

    void dfs(int root) {
      if (root >= this->n) { return; }
      cout << root << " " << seg[root] << endl;
      dfs(root*2 + 1);
      dfs(root*2 + 2);
    }

    void bfs() {
      queue<int> q;
      q.push(0);
      while(!q.empty()) {
        int nn = q.size();
        for (int i = 0; i < nn; i++) {
          int top = q.front(); q.pop();
          cout << top << ":(" << seg[top] << ") ";
          if (2*top + 1 <= 3*n) q.push(top*2+1);
          if (2*top + 2 <= 3*n) q.push(top*2+2);
        }
        cout << endl;
      }
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
      vector<vector<int>> res;
      if (buildings.size() == 0) return res;

      // sort and remove dupes of all x start and end points of every building
      set<int> positions;
      for (auto b : buildings) {
        positions.insert(b[0]);
        positions.insert(b[1]);
      }

      // set the number of positions, 
      this->n = positions.size();
      vector<int> pos_list(positions.begin(), positions.end());

      // maps absolute x position to an index [0, n)
      unordered_map<int, int> pos2idx; 
      int i = 0;
      for (auto& pos : positions) pos2idx[pos] = i++;

      // build seg tree
      buildtree();

      // scanline of each building from left to right
      for (auto b : buildings) {
        int left = pos2idx[b[0]];
        int right = pos2idx[b[1]];
        int height = b[2];
        modify(left, right, height);
      }

      bfs();

      int last = 0;
      for (auto pos : positions) {
        int h = query(pos2idx[pos]);
        // cerr << pos2idx[pos] << " " << h << endl;
        if (h != last) {
          res.push_back({pos, h});
        }
      }
      res.push_back({*positions.rbegin(), 0});

      return res;
    }
};

int main() {
  Solution s;
  vector<vector<int>> buildings =
  {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
  auto res = s.getSkyline(buildings);
  for (auto v : res) {
    // cout << v[0] << " " << v[1] << endl;
  }
}
