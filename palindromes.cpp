#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;
  cin >> s;
  int n = s.size();
  // odd len palindromes
  for (int m = 0; m < n; m++) {
    for (int len = 0; m - len >= 0 && m + len < n; len++) {
      cout << s.substr(m - len, len) << " " << s[m] << " " << s.substr(m + 1, len) << endl;
    }
  }
  cout << endl;

  // even len palindromes
  for (int m = 0; m < n; m++) {
    for (int len = 1; m - len + 1 >= 0 && m + len < n; len++) {
      cout << s.substr(m - len + 1, len) << " " << s.substr(m + 1, len) << endl;
    }
  }
}
