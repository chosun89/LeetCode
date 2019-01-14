#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int maxEnvelopes(vector<pair<int, int>>& env) {
        if (env.size() == 0) return 0;
        
        sort(env.begin(), env.end(), [](pair<int, int>a, pair<int, int>b) {
          if (a.first == b.first) 
            return a.second > b.second;
          else return a.first < b.first;
        });
        
        int n = env.size();
        vector<int> dp (n, INT_MAX);
        dp[0] = INT_MIN;
        int last = 0; 

        for (auto a : env) {
            int l = 0, r = last; 
            while (l <= r) {
                int m = l + (r-l)/2;
                if (dp[m] < a.second) l = m + 1;
                else r = m - 1;
            }
            dp[l] = a.second;
            if (last < l) last = l;
        }
       return last; 
    }
};

int main() {
  Solution sol;
  //vector <pair <int,int> > arr = { {2,100}, {3,200}, {4,300}, {5,500}, {5,400}, {5,250}, {6,370}, {6,360}, {7,380} };
  vector <pair <int,int> > arr = { {2,100}, {3,200}, {4,300}, {5,400}, {5,250} };
  cout << sol.maxEnvelopes(arr) << endl;
  for (auto p : arr) cout << p.first << ", " << p.second << endl;

}
