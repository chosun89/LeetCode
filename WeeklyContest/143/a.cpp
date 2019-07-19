#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> distributeCandies(int candies, int num) {


        vector<int> res(num, 0);
        int i = 0;
        while(candies - (i + 1) > 0) {
            res[i % num] += (i + 1);
            candies -= (i+1);
            i++;
        }

        res[i % num] += candies;

        return res;
    }


};

int main() {
    Solution s;
    auto res = s.distributeCandies(10,3);
    for (auto s : res) cout << s <<  " " ;
}

