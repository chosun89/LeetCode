#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
      int n = time.size();

      vector<int> mp (60, 0);

      for (int i = 0; i < n; i++) {
        mp[time[i] % 60]++;
      }

      int sum = 0;
      sum += (mp[0])*(mp[0] - 1)/2;
      for (int i = 1; i <= 30 && i != 60 - i; i++) {
        sum += mp[i]*mp[60 - i];
      }

      return sum + (mp[30])*(mp[30]-1) / 2;
    }
};

int main() {
  Solution s;
  vector<int> time = {15,63,451,213,37,209,343,319 };
  cout << s.numPairsDivisibleBy60(time) << endl;

}

