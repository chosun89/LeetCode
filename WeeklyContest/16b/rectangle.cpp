#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
      if (area == 0) return {0,0};
      vector<int> res;
      for (int a = sqrt(area); a >= 0; a--) {
        if (area % a == 0) {
          res.pb(area / a);
          res.pb(a);
          break;
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> res =  s.constructRectangle(48);
  for (auto a : res) cout << a << " ";
}

