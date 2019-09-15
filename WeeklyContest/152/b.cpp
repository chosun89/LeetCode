#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
  int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {
    int T = 0;
    int i = 0, j = 0;
    int n = calories.size();
    int res = 0;
    while(i < k) {
      T += calories[i];
      i++;
    }
    if (T < lower)
      res--;
    else if (T > upper)
      res++;

    while (i < n) {
      T += calories[i];
      T -= calories[j];

      if (T < lower)
        res--;
      else if (T > upper)
        res++;

      i++, j++;
    };

    return res;

  }
};

int main() {

  Solution s;
  vector<int> calories = {3,2};
  int k = 2;
  int lower = 0;
  int upper = 1;
  cout << s.dietPlanPerformance(calories,k,lower,upper) << endl;

}

