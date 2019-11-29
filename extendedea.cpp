#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int gcd(int a, int b) {
  return (a%b) ? gcd(b, a%b) : b;
}

int inverse(int a, int m) {
  int u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

pair<int,int> extendedEA(int a, int b) {
  int s = 1, s2 = 0, t = 0, t2 = 1;
  while(b > 0) {
    int q = a/b;
    int temp = s2;

    s2 = s - q*s2;
    s = temp;

    temp = t2;
    t2 = t - q*t2;
    t = temp;

    cout << s << " " << t << endl;

    temp = b;
    b = a % b;
    a = temp;
  }


  return {s, t};
}

int main() {
  // cout << gcd(1511, 2003) << endl; 
  pair<int,int> res = extendedEA(2003, 1511);
  cout << res.first << " " << res.second << endl;

}
