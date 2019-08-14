#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
    int a = 0, b = 1, c = 1;
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 1;
    else {
        for (int i = 3; i <= n; i++) {
            int tempc = c;
            c = a + b + c;
            a = b;
            b = tempc;
        }
        return c;
    }

    return -1;
    }

};

int main() {
    Solution s;
    int n = 0;
    cout << s.tribonacci(n) << endl;
}

