#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;

class Solution {
public:
  string decodeAtIndex(string S, int K) {
    if (K == 1) return S.substr(0,1);
    int n = S.size();
    long long length = 0;
    int i ;
    for (i = 0; i < n; i++) {
      if (isalpha(S[i])) 
        length++;
      else 
        length *= (S[i] - '0');
    }
    while (i--) {
      if (isdigit(S[i])) {
        length /= (S[i] - '0');
        K %= length;
      }
      else length--;
      if (length == K) return S.substr(i,1);
    }
    return "jeff";
  }
}; 

int main() {
  Solution S;
  string lol1 = ("leet2code3");
  string lol2 = ("ha22");
  string lol3 = ("a2345678999999999999999");
  string lol4 = "a23";
  cout << S.decodeAtIndex(lol1, 10) << endl;
  cout << S.decodeAtIndex(lol2, 5) << endl;
  cout << S.decodeAtIndex(lol3, 1) << endl;
  cout << S.decodeAtIndex(lol4, 6) << endl;
}

