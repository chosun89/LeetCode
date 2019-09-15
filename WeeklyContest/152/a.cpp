#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:

  int mod = 1e9 + 7;

  int sieve(int n) {
    vector<int>prime(n+1, 0);

    for (int i = 2; i <= sqrt(n); i++) {
      if(prime[i] == 0) {
        for (int j = 2*i; j <= n; j+=i) {
          prime[j]++;
        }
      }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
      if (prime[i] == 0)
        count++;
    }
    return count;
  }

  int numPrimeArrangements(int n) {
    int res;
    int primes = sieve(n);

    long long prod = 1;
    for (int i = 1; i <= primes; i++) {
      prod = (prod * i) % mod;
    }

    long long comp = 1;
    for (int i = 1; i <= (n - primes); i++) {
      comp = (comp * i) % mod;
    }

    res = (comp * prod) % mod;
    return res;
  }
};

int main() {
  Solution s;
  int n = 100;
  cout << s.numPrimeArrangements(n) << endl;

}

