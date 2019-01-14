#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
      unordered_map<string, pair<int, int>> l1; 

      int n = list1.size();
      int m = list2.size();
      FOR(i,0,n) {
        l1[ list1[i] ].first = i;
      }
      vector<int> found (n, 0);
      int mini = INT_MAX;
      FOR (i,0,m) {
        if ( l1.find( list2[i] ) != l1.end() ) {
          found[ l1[list2[i]].first] = 1;
          l1[ list2[i] ].second = l1[list2[i]].first + i;
          mini = min(mini, l1[ list2[i] ].second);
        }
      }

      vector<string> res;
      for (auto p : l1) {
        if (found[p.second.first] && p.second.second == mini) {
          res.pb(p.first);
        }
      }

      return res;
       
    }
};

int main() {
  Solution s;
  vector<string> l1 = { "Shogun", "Tapioca Express", "Burger King", "KFC" };
	vector<string> l2 = { "Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun" };
  vector<string> res = s.findRestaurant(l1, l2);
  for (auto s : res) cout << s << " ";
  cout << endl;

}

