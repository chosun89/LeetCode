#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class MagicDictionary {
public:
    unordered_map<string, set<pair<int,int>> > m;
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
      for (auto s : dict) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
          string fir = s.substr(0,i) + s.substr(i+1, string::npos);
          m[fir].insert({i, });
        }
      }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
      int n = word.size();
      for (auto p : m) {
        for (auto poss : p.second)
          if (n != poss.size()) return false;
          else if (poss.compare(word) == 0) return true;
      }
      return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

int main() {
  MagicDictionary m;
  vector<string> dict = { "hello", "leetcode" };
  vector<string> finder = { "hllo" , "", "eetcode", "leetcde", "leetcode" };
  m.buildDict(dict);
  for (auto s : finder) {
    cout << m.search(s) << endl;
  }

}

