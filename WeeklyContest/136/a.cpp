#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    bool isRobotBounded(string inst) {

      inst = inst+inst+inst+inst;
      int x = 0, y = 0;
      int dir = 0; // N, E, S, W

      for (char c : inst) {
        if (c == 'L')
          dir = (dir - 1 + 4) % 4;

        else if (c == 'R')
          dir = (dir + 1) % 4;

        else {
          if (dir == 0) {
            y++;
          }
          else if (dir == 1) {
            x++;
          }
          else if (dir == 2) {
            y--;
          }
          else {
            x--;
          }
        }
      }

      return (x == 0 && y == 0);
        
    }
};

int main() {
  Solution s;
  cout << s.isRobotBounded("GGLLGG") << endl;


}

