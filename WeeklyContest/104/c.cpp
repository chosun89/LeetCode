#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {

      // char -> quantity
      vector<unordered_map<char,int>> vmpA;
      vector<unordered_map<char,int>> vmpB;
      vector<string> res;

      for (auto s : A) {
        unordered_map<char,int> mp;
        for (char c : s) {
          mp[c]++;
        }
        vmpA.pb(mp);
      }

      for (auto s : B) {
        unordered_map<char,int> mp;
        for (char c : s) {
          mp[c]++;
        }
        vmpB.pb(mp);
      }
      
      int i = 0;
      for (auto mA : vmpA) {
        bool isvalid = true;
        for (auto mB : vmpB) {
          if (!Contains(mA,mB)) {
            isvalid = false;
            break;
          }
        }
        if (isvalid) {
          res.pb(A[i]);
        }
        i++;
      }

      return res;

    }
    // compares two words from A and B
    bool Contains(unordered_map<char,int> A, unordered_map<char,int> B) {
      for (auto b : B) {
        char cb = b.first;
        if (A.find(cb) == A.end() || A[cb] < b.second) 
          return false;
      }
      return true;
    }
};

int main() {
  Solution s;
  vector<string> A = {"amazon","apple","facebook","google","leetcode"};
  vector<string> B = {"e", "oo"};
  vector<string> res = s.wordSubsets(A,B);
  for (auto a : res) cout << a << " ";

}

