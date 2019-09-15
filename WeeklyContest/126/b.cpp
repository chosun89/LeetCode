#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool isValid(string S) {
      int n = S.size();
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (S[i] == 'a') {
          count++;
        }
        else if (S[i] == 'b') {
          count--;
        }
        if (count < 0) return false;
      }
      if (count != 0) return false;
      count = 0;
      for (int i = 0; i < n; i++) {
        if (S[i] == 'a') {
          count++;
        }
        else if (S[i] == 'c') {
          count--;
        }
        if (count < 0) return false;
      }

      if (count != 0) return false;
      count = 0;
      for (int i = 0; i < n; i++) {
        if (S[i] == 'b') {
          count++;
        }
        else if (S[i] == 'c') {
          count--;
        }
        if (count < 0) return false;
      }
      if (count != 0) return false;
      count = 0;
      return true;

    }
};

int main() {
  Solution s;
  string S = "cababc";
  cout << s.isValid(S) << endl;

}

