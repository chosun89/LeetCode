#include <bits/stdc++.h>
using namespace std;

int main() {

  string s;
  cin >> s;
  int n = s.size();
  auto substr = [&](int i, int j) {
    return s.substr(i, j - i);
  };
  // odd len palindromes
  for (int m = 0; m < n; m++) {
    for (int len = 0; m - len >= 0 && m + len < n; len++) {
      cout << substr(m - len, m) << " ";
      cout << substr(m, m + len + 1) << endl;
    }
  }
  cout << endl;

  // even len palindromes
  for (int m = 0; m < n; m++) {
    for (int len = 1; m - len + 1 >= 0 && m + len < n; len++) {
      cout << substr(m - len + 1, m) << " " << substr(m, m + len + 1) << endl;
    }
  }

}

