#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
      vector<string> res;
      if (A.size() == 0 && B.size() == 0) return res;
      int n = A.size();
      int m = B.size();
      map<string, int> Amap;
      
      for (int i = 0, j = 0; j <= n; j++) {
        if (A[j] == ' ' || j == n) {
          Amap[ A.substr(i,j - i) ]++;
          i = j + 1;
        }
      }

      for (int i = 0, j = 0; j <= m; j++) {
        if (B[j] == ' ' || j == m) {
          Amap[ B.substr(i,j - i) ]++;
          i = j + 1;
        }
      }

      for (auto p : Amap) {
        if (p.second == 1) {
          res.push_back(p.first);
        }
      }
      return res;
    }
};

int main() {
  Solution s;
  string A = "this apple is sweet";
  string B = "this apple is sour";
  //string A = "apple apple";
  //string B = "banana";

  vector<string> res = s.uncommonFromSentences(A,B);
  for (auto s : res)
    cout << s << endl;

}

