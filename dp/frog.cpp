#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;


// first jump k0 = 1 unit
// all preceding jumps = k - 1 or k + 1
// stones[i] = distance of stone from start
unordered_map<int, bool> dp;
bool canCross(vi& stones, int pos = 0, int k = 0) {
  int key = pos | k << 11;

  if (dp.count(key) > 0)
      return dp[key];

  for (int i = pos + 1; i < stones.size(); i++) {
      int gap = stones[i] - stones[pos];
      if (gap < k - 1)
          continue;
      if (gap > k + 1)
          return dp[key] = false;
      if (canCross(stones, i, gap))
          return dp[key] = true;
  }

  return dp[key] = (pos == stones.size() - 1);
}

int main() {
  vi stones = { 0,1,3,5,6,8,12,17 };
  canCross(stones);
}


