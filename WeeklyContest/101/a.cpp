#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class RLEIterator {
public:
    
    queue< pair<int,int> > q;
    RLEIterator(vector<int> A) {
      for (int i = 0; i < A.size(); i+=2) {
        if (A[i] == 0) continue;
        q.push({A[i], A[i+1]});
      }
    }
    
    int next(int n) {

      while (!q.empty()) {
        auto top = q.front();
        int remain = top.first;
        int ele = top.second;

        if (remain - n < 0) {
          n -= remain;
          q.pop();
          continue;
        }
        else if (remain - n == 0) {
          q.pop();
          return ele;
        }
        else {
          q.front().first-=n;
          return ele;
        }
      }
      return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */

int main() {
  vector<int> A = { 3,8,0,9,2,5};
  RLEIterator s(A);
  cout << s.next(4) << endl;
  cout << s.next(1) << endl;
  cout << s.next(1) << endl;
  cout << s.next(2) << endl;

}

