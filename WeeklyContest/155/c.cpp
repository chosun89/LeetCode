#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uni(vector<int>& uf, int u, int v) {
      int pu = ufind(uf, u);
      int pv = ufind(uf, v);
      if (pv == pu) return false;
      uf[pu] = pv;
      return true;
    }

    int ufind(vector<int>& uf, int u) {
      return (u == uf[u]) ? u : uf[u] = ufind(uf, uf[u]);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      int n = s.size();
      vector<int> uf;
      for (int i = 0; i < n; i++) uf.push_back(i);
      for (auto& p : pairs) uni(uf, p[0], p[1]);
      vector<vector<int>> components(n, vector<int>());

      for (int i = 0; i < n; i++) {
        int p = ufind(uf, i);
        components[p].push_back(i);
      }

      for (auto& comp : components) {
        string chars = "";

        for (auto i : comp) {
          chars += s[i];
        }

        sort(chars.begin(), chars.end());

        for (int i = 0; i < chars.size(); i++){
          s[comp[i]] = chars[i];
        }
      }
      return s;
    }
};

int main() {
  Solution ss;
  string s = "cba";
  vector<vector<int>> pairs = { {0,1}, {1,2} };
  cout << ss.smallestStringWithSwaps(s, pairs) << endl;

}

