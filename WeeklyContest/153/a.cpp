#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& dist, int start, int end) {
      if (start > end)
        swap(start, end);

      int total = 0;
      int path = 0;
      for (int i = 0; i < dist.size(); i++) {
        total += dist[i];
        if (i >= start && i < end) {
          path += dist[i];
        }
      }

      return min(path, total - path);
    }
};

int main() {
  Solution s;
  int st = 0, e = 3;
  vector<int> dist = {1,2,3,4};
  cout << s.distanceBetweenBusStops(dist,st,e) << endl;

}

