#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
      char c; int count;
      // char -> count
      vector<pair<int,int>> match;
      vector<pair<int,int>> matchtyped;
      for (int i = 0; i < name.size(); i++) {
        c = name[i];
        count = 1;
        while (i < name.size() - 1 && name[i] == name[i+1]) {
          i++;
          count++;
        }
        match.pb({c-'a', count});
      }

      for (int i = 0; i < typed.size(); i++) {
        c = typed[i];
        count = 1;
        while (i < typed.size() - 1 && typed[i] == typed[i+1]) {
          i++;
          count++;
        }
        matchtyped.pb({c-'a', count});
      }

      if (matchtyped.size() != match.size()) return false;
      else {
        for (int i = 0; i < match.size(); i++) {
          if (match[i].first != matchtyped[i].first) return false; 
          if (match[i].second > matchtyped[i].second ) return false;
        }

        return true;
      }
      return true;
    }

};

int main() {
  Solution s;
  string name = "saeed";
  string typed = "ssaaedd";
  cout << s.isLongPressedName(name,typed) << endl;

}

