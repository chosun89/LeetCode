#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
      int N = people.size();
      sort(people.begin(), people.end());
      //int boat = 0;
      int sum = 0;
      int res = 0;
      for (int i = 0, j = N - 1; i <= j;) {
        sum += people[j];
        j--;
        if (sum + people[i] <= limit) {
          i++;
        }
        sum = 0;
        res++;
      }
      return res;
    }
};

int main() {
  Solution s;
  vector<int> v = {1,2};
  vector<int> v2 = { 3 , 2 , 2, 1};
  vector<int> v3 = {3,5,3,4};
  vector<int> v4 = { 5 , 1 , 4, 2 };
  cout << s.numRescueBoats( v, 3) << endl;
  cout << s.numRescueBoats( v2, 3) << endl;
  cout << s.numRescueBoats( v3, 5) << endl;
  cout << s.numRescueBoats( v4, 6) << endl;
}

