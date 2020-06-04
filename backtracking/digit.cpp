#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define pb push_back
#define fi first
#define se second
#define ALL(a) (a.begin(), a.end())
using ll = long long;
template<typename T> void Out(T x) { cout << x << endl; }
const int mod = 1e9 + 7;
const int N = 500 + 10;
const int M = 50 + 10;
int dp[N][M][2][2];
const int md = 1e9 + 7;

class Solution {
public:

vector<int> kmp(const string& t) {
  int m = t.size();
  vector<int> f(m);
  f[0] = 0;
  int i = 1, len = 0;
  for (; i < m; ++i) {
    while (len > 0 && t[len] != t[i]) len = f[len - 1];
    if (t[len] == t[i]) len++;
    f[i] = len;
  }
  return f;
}

string s, t, evil;
vector<int> f;

int dfs(int pos, int p, int eq1, int eq2) {
  // if we have constructed a string length 
  if (pos == s.size()) return 1;

  int& r = dp[pos][p][eq1][eq2];
  if (r == -1) {
    r = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      // new string cannot be lexicographically smaller than A or greater than B
      if (eq1 && c < s[pos]) continue; 
      if (eq2 && c > t[pos]) continue;

      // KMP
      int pp = p;
      while(pp > 0 && evil[pp] != c) pp = f[pp-1];
      if (evil[pp] == c) ++pp;
      // if new string matches Evil, skip it
      if (pp == evil.size()) continue;

      r += dfs(pos + 1, pp, eq1 && (c == s[pos]), eq2 && (c == t[pos]));
      if (r >= mod) r -= mod;
    }
  }
  return r;
}

  int findGoodStrings(int n, string s1, string s2, string evil) {
    this->s = s1, this->t = s2, this->evil = evil;
    this->f = kmp(evil);
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 1, 1);
  }
};

int main() {
  Solution s;
}
