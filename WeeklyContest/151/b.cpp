#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int f(string& w) {
      int az[26] = {};

      for (int i = 0; i < w.size(); i++) {
        az[w[i] - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        if (az[i] > 0) return az[i];
      }
      return 0;
    }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
      vector<int> f_arr;
      vector<int> res;

      for (auto& w : words) {
        f_arr.pb(f(w));
      }

      for (auto& q : queries) {
        int count = 0;
        int f_q = f(q);
        for (int i = 0; i < words.size(); i++) {
          if (f_q < f_arr[i])
            count++;
        }
        res.pb(count);
      }
      return res;

    }
};

int main() {

  Solution s;
  vector<string> queries = {"bbb","cc"};
  vector<string> words = {"a","aa","aaa","aaaa"};
	vector<int> res = s.numSmallerByFrequency(queries, words);
  for (auto i : res) cout << i << endl;

}

