#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
      unordered_map<char,pair<int,bool>> mp = parse(S);
      int count = 0;
      for (auto str : words) {
        auto mp2 = parse(str);

        if (mp2.size() != mp.size()) continue;
        else {
          bool ok = true;
          for (auto it = mp.begin(), it2 = mp2.begin(); it != mp.end(); it++,it2++) {
            if (it->first == it2->first) {
              if (it->second.first == it2->second.first) {
                continue;
              } else if (it->second.second){
                continue;
              }
              else {
                ok = false; break;
              }
            } else {
              ok = false;
              break;
            }
          }
          if (ok) count++;

        }
      }
      return count;
    }

    unordered_map<char,pair<int,bool>> parse(string& str) {
      unordered_map<char,pair<int,bool>> mp;
      int n = str.size();
      string small;
      int idx = 0;
      for (int i = 0; i < n;) {
        char c = str[i];
        int count = 1;
        int j = i + 1;
        while(j < n && str[j] == c) {
          count++;
          j++;
        }
        mp[c].first = count;
        if (count <= 2) {
          mp[c].second = false;
        }
        else if (count >= 3) {
          mp[c].second = true;
        }
        i = j;
        idx++;
      }
      return mp;
    }
};

int main() {
  Solution s;
  //string S = "heeellooo";
  string S = "zzzzzyyyyy";
	vector<string> words = {"zzyy","zy","zyy"};
  //vector<string> words = {"hello","hi","helo"};
  cout << s.expressiveWords(S,words) << endl;

}

