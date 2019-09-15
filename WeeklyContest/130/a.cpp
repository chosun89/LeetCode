#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string S) {

      vector<char> stak;
      string parse = "";
      string res = "";
      for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
          parse += '(';
          stak.pb('(');
        }
        else if (S[i] == ')') {
          parse += ')';
          stak.pop_back();
        }

        if (stak.size() == 0) {
					// cout << parse.substr(1, parse.size()-2) << endl;
          res += parse.substr(1, parse.size()-2);
          parse = "";
        }
      }

      return res;
        
    }
};

int main() {

  Solution s;
  // string str = "(()())(())(()(()))";
  string str = "()()";
  cout << s.removeOuterParentheses(str) << endl;

}

