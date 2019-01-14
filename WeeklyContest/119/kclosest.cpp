#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

bool cmp(vector<int> A, vector<int> B) {

  return (sqrt(A[0]*A[0] + A[1]*A[1]) < sqrt(B[0]*B[0] + B[1]*B[1]));

}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
      sort(points.begin(), points.end(), cmp);
      vector< vector<int> > res;

      for (int i = 0; i < K; i++) {
        res.pb(points[i]);
      }

      return res;
        
    }
};

int main() {
  Solution S;
  vector< vector<int> > A = { {3,3}, {5,-1}, {-2,4}};
  vector< vector<int> > res;
  res = S.kClosest(A, 2);
  for (auto p : res)
    cout << p[0] << ", " << p[1] << endl;


}

