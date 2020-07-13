#include<bits/stdc++.h>
using namespace std;

const int inf = 5010;
int f[21][inf][inf];
class Solution {
public:
    vector<int> r;
    int n;
    
    int dfs(int i, int set1, int set2) {
        if (i == n) return (set1 == set2) ? set1 : -inf;
        int& res = f[i][set1][set2];
        if (res != -1) return res;
        res = -inf;
        res = max(res, dfs(i + 1, r[i] + set1, set2));
        res = max(res, dfs(i + 1, set1, set2 + r[i]));
        res = max(res, dfs(i + 1, set1, set2));
        //cout << res << endl;
        return res;
    }
    int tallestBillboard(vector<int>& rods) {
        this->r = rods;
        this->n = r.size();
        memset(f, -1, sizeof(f));
        return dfs(0, 0, 0);
    }
};

int main() {
  Solution s;
  vector<int> rods = {1, 2, 3, 4, 5, 6 };
  cout << s.tallestBillboard(rods) << endl;
}
