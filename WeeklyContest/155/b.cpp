#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;


class Solution {
public:
    int gcd(int a, int b) {
      return (a%b) ? gcd(b,a%b) : b;
    }

    ll lcm(ll a, ll b) {
      return a*b / gcd(a,b);
    }

    ll findCount(ll n, ll a, ll b, ll c) {
      return ((n/a) + (n/b) + (n/c) - (n/lcm(a,c)) - (n/lcm(a,b)) - (n/lcm(b,c)) + (n/(lcm(lcm(a,b),c))));
    }

    int nthUglyNumber(int n, int a, int b, int c) {
      ll l = 1;
      ll r = (ll) max(a, max(b,c)) * (ll) n;
      ll mid;

      while(l <= r) {
        mid = l + (r - l) / 2;

        if (findCount(mid,a,b,c) < n) {
          l = mid + 1;
        }
        else {
          r = mid - 1;
        }
      }

      return l;
    }
};

int main() {
  Solution s;
  int n,a,b,c;
  //n = 10, a = 2, b = 3, c = 5;
  //n = 4, a = 2, b = 3, c = 4;
  //n = 5, a = 2, b = 11, c = 13;
  //n = 1000000000, a = 2, b = 217983653, c = 336916467;
  n = 1000000000, a = 2, b = 430081563, c = 604870735;
  //cout << gcd(b,c) << endl;
  cout << s.nthUglyNumber(n,a,b,c) << endl;
}

