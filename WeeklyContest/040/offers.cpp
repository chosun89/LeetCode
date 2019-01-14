#include <bits/stdc++.h>
using namespace std;
int operator* (const vector<int>& needs, const vector<int>& price) {
  int sum = 0;
  for (int i = 0; i < needs.size(); i++) {
    sum += needs[i] * price[i];
  }
  return sum;
}

bool operator<(const vector<int>& needs, const int& n) {
    for (auto a : needs) {
      if (a < n)
        return true;
    }
    return false;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int currcost = 0) {
			if (needs < 0) return INT_MAX;
			int m = currcost + needs * price;
      for (vector<int> offer : special) {
        for (int i = 0; i < needs.size(); i++) 
          needs[i] -= offer[i];

        m = min (m, shoppingOffers(price, special, needs, currcost + offer[needs.size()]));

        for (int i = 0; i < needs.size(); i++) 
          needs[i] += offer[i];
      }
      return m;
    }
};

int main() {

	vector<int> price = {2,3,4}; 
  vector< vector<int> > special = {{1,1,0,4},{2,2,1,9}}; 
  vector<int> needs = {1,2,1};
  Solution s;
  cout << s.shoppingOffers(price, special, needs) << endl;
}

