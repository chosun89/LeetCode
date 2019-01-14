#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

const int maxn = 2e5;
int id [maxn], ran[maxn];
class Solution {
public:
    class DSU {
      public: 
        int Num;
        int maxrank;

        DSU (int n) {
          Num = n;
          maxrank = 1;
          FOR(i,0,n) {
            id[i] = i;
            ran[i] = 1;
          }
        }

        int find (int u) {
          while (id[u] != u) {
            id[u] = id[ id[u] ];
            u = id[u];
          }
          return u;
        }

        void uni (int u, int v) {
          int pu = find(u);
          int pv = find(v);

          id[pv] = pu;

          ran[pu] += ran[pv];
          ran[pv] = 0;

          if (ran[pu] > maxrank) {
            maxrank = ran[pu];
          }

        }

      int getmax() { return maxrank; }
    };

    int arrayNesting(vector<int>& nums) {
      int n = nums.size();
      DSU dsu(n);
      int i = 0;
      int u = 0;
      int v = nums[u];
      while(i < n) {
        dsu.uni(u, v);
        u = v;
        v = nums[u];
        i++;
      }
      return dsu.getmax();
    }
};

int main() {

  Solution s;
  vector<int> nums = { 5,4,0,3,1,6,2};

  cout << s.arrayNesting(nums) << endl;
}

