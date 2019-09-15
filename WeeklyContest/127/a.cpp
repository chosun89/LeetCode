#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
      priority_queue<int,vector<int>, greater<int> > pq;

      int sum = 0;
      for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        pq.push({A[i]});
      }


      for (int i = 0; i < K; i++) {
        int top = pq.top();
        pq.pop();
        sum -= top;
        sum += (-1*top);
        pq.push({-1*top});
      }


        return sum;
    }
};

int main() {
  Solution s;
  vector<int> A = {2,-3,-1,5,-4};
  int K = 2;
  cout << s.largestSumAfterKNegations(A,K) << endl;

}

