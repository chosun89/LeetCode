#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

int lowerbound(vector<int> a, int find) {
  int l = 0, r = a.size() - 1;

  while (l <= r) {
    int mid = (l + r) >> 1;
    if (find <= a[mid]) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
}

int upperbound(vector<int> a, int find) {
  int l = 0, r = a.size() - 1;

  while (l <= r) {
    int mid = (l + r) >> 1;
    if (find < a[mid]) {
      r = mid - 1;
    }
    else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {

  vector<int> a = { 0, 1, 1, 2, 2, 2, 2, 3,3,3,3,3,3 };
  int find = 3;
  cout << lowerbound(a, find) << endl;
  cout << upperbound(a, find) << endl;
}
