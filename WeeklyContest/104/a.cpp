#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    
    int gcd (int a, int b) {
      return (b) ? (gcd(b, a%b)) : a;
    }

    bool hasGroupsSizeX(vector<int>& deck) {
      
      int n = deck.size();
      if (n == 1) return false;

      unordered_map<int,int> mp;

      for (int i = 0; i < n; i++) {
        mp[deck[i]]++;
      }

      int mini = 1 << 20;
      // a singleton cannot partition into at least doubleton
      for(auto p : mp) {
        if (p.second == 1) return false;
        mini = min (mini, p.second);
      }
      cout << mini << endl;
        
      for (auto p : mp) {
        if (gcd(p.second, mini) == 1) return false;
      }
      return true;
    }
};

int main() {
  Solution s;
  //cout << s.gcd(550,100) << endl;
  //vector<int>deck = {1,2,3,4,4,3,2,1};
  vector<int>deck={0,0,0,1,1,1,2,2,2};
  cout << s.hasGroupsSizeX(deck) << endl;

}

