#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while(label) {
            res.push_back(label);
            label >>= 1;
        }

        reverse(res.begin(), res.end());
        for (auto r : res) cout << r << " ";

        for (int i = 1; i < res.size(); i+=2) {
            res[i] = res[i] ^ ((1 << i) - 1);
            cout << res[i] << endl;
        }
        return res;
    }

};

int main() {
    Solution s;
    int label = 14;
    auto res = s.pathInZigZagTree(label);
    for (auto r : res) cout << r << " ";
}

