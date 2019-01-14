#include <bits/stdc++.h>
using namespace std;

int main() {
  int xorsum = 0;
  for (int i = 1; i < 1000 - 1; i++) {
    xorsum ^= i;
    cout << xorsum << " ";
  }

}

