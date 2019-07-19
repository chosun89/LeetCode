#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {

        vector<int> res;
        unordered_map<int,int> cache;
        vector<int> rem;

        for (int i = 0; i < arr1.size(); i++) {
            cache[arr1[i]]++;
        }

        for (int i = 0; i < arr2.size(); i++) {
            if (cache.find(arr2[i]) != cache.end()) {
                for (int j = 0; j < cache[arr2[i]]; j++) {
                    res.push_back(arr2[i]);
                }
                cache.erase(arr2[i]);
            }
        }

        for (auto p : cache) {
            for (int i = 0; i < p.second; i++) {
                rem.push_back(p.first);
            }
        }

        sort(rem.begin(), rem.end());
        res.insert(res.end(),rem.begin(), rem.end());

        return res;
    }


};

int main() {
    Solution s;
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    auto res = s.relativeSortArray(arr1, arr2);
    for (auto s : res) cout << s << " ";
}

