#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:

    int cross(vector<int> a, vector<int> b) {

      return a[1] * b[0] - a[0] * b[1];
    }

    bool isBoomerang(vector<vector<int>>& points) {

      vector<int> a = { points[0][0] - points[1][0], points[0][1] - points[1][1] };
      vector<int> b = { points[2][0] - points[1][0], points[2][1] - points[1][1] };

      if (cross(a , b) == 0) return false;
      else return true;
        
    }
};

int main() {
  Solution s;
  // vector<vector<int>> points = { {1,1}, {2,3}, {3,2} };
  // vector<vector<int>> points = { {1,1}, {2,2}, {3,3} };
  cout << s.isBoomerang(points) << endl;

}

