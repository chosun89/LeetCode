#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string solveEquation(string str) {
      if (str == "") return "No Solution";
      int i = 0;
      while (str[i] != '=') {
        i++;
      }
      string eq1 = str.substr(0, i);
      string eq2 = str.substr(i + 1);
      //cerr << "eq2: " << eq2 << endl;
      int varsum1 = 0;
      int varsum2 = 0;
      int numsum1 = 0;
      int numsum2 = 0;

      parse(eq1, varsum1, numsum1); 
      //cout << "varsum1: " << varsum1 << " numsum1: " << numsum1 << endl;
      parse(eq2, varsum2, numsum2);
      //cout << "varsum2: " << varsum2 << " numsum2: " << numsum2 << endl;

      int vartot = varsum2 - varsum1;
      int numtot = numsum1 - numsum2;
      if (vartot == 0 && numtot == 0) return "Infinite solutions";
      else if (vartot == 0 && numtot != 0) return "No solution";
      else {
        numtot /= (vartot * 1.0);
        return "x=" + to_string(numtot); 

      }
      return str;
    }

    void parse (string s, int& varsum, int& numsum) {
      int n = s.size();
      int sf = 1;
      int i = 0;
      while (i < n) {
        int coeff = 0;
        if (s[i] == '-') {sf = -1; i++;continue;}
        else if (s[i] == '+') {sf = 1;i++; continue;}
        if (s[i] == 'x') {varsum += sf; i++; continue;};

        if (isdigit(s[i])) {
          while (i < n && isdigit(s[i])) {
            coeff *= 10;
            coeff += (s[i] - '0');
            i++;
          }
          if (i >= n) {
            if (s[n-1] == 'x') {varsum += coeff*sf;}
            else numsum += coeff *sf;
            return;
          }
          else if (s[i] == 'x') {
            varsum += coeff*sf;
            i++;
            continue;
          }
          else {
            numsum += coeff*sf;
            continue;
          }
        }
      }
      return;
    }
};

int main() {
  Solution s;
  string str1 = "2x+3x-6x=x+2";
  string str2 = "x+5-3+x=6+x-2";
  string str3= "x=x";
  string str4= "x=x+2";
  cout << s.solveEquation(str4) << endl;

}

