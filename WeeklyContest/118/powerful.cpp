#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        
      unordered_map<int,int> mp;
      vector<int> res;

      for (int a = 1; a <= bound; a *= x) {
        int b = 1;
        for (; a + b <= bound; b *= y) {
            mp[a+b]++;
            if (y == 1) break;
        }
        if (x == 1) break;
      }

      for (auto p : mp) 
        res.pb(p.first);

      return res;
    }

};

int main() {
  Solution s;
  vector<int> res = s.powerfulIntegers(1,1,10);
  for (auto a : res) cout << a << " ";

}

