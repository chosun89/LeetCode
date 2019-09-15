#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {


      int n = stones.size();

      while(n >= 2){
        sort(stones.begin(), stones.end());
        n = stones.size();

        int x = stones[n-2];
        int y = stones[n-1];

        stones.pop_back();
        stones.pop_back();

        if (x != y) {
          stones.pb(y-x);
        }

        n = stones.size();

      }

      if(stones.size() == 1) return stones[0];
      else return 0;
        
    }
};

int main() {
  Solution s;
  vector<int> stones = {2,7,4,1,8,1};
  cout << s.lastStoneWeight(stones) << endl;

}

