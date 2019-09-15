#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // (r , c)
    pair<int, int> coord(char a) {
        return { (a - 'a') / 5, (a - 'a') % 5 };
    }

    string alphabetBoardPath(string target) {
        string res = "";

        int currr = 0, currc = 0;
        for (int i = 0; i < target.size(); i++) {
            auto next = coord(target[i]);
            int dr = next.first - currr;
            int dc = next.second - currc;
        
            if (dr == 0 && dc == 0) {
                currr = next.first;
                currc = next.second;
                res += "!";
                continue;
            }

            if (target[i] == 'z') {
                if (dc < 0) {
                    for (int j = 0; j < -dc; j++) res += "L";
                }
                else if (dc > 0) {
                    for (int j = 0; j < dc; j++) res += "R";
                }
                if (dr < 0) {
                    for (int j = 0; j < -dr; j++) res += "U";
                }
                else if (dr > 0) {
                    for (int j = 0; j < dr; j++) res += "D";
                }
                currr = next.first;
                currc = next.second;
                res+="!";
                continue;

            }
            if (dr < 0) {
                for (int j = 0; j < -dr; j++) res += "U";
            }
            else if (dr > 0) {
                for (int j = 0; j < dr; j++) res += "D";
            }
            if (dc < 0) {
                for (int j = 0; j < -dc; j++) res += "L";
            }
            else if (dc > 0) {
                for (int j = 0; j < dc; j++) res += "R";
            }
            currr = next.first;
            currc = next.second;
            res+="!";
        }

        return res;
    }

};

int main() {
    Solution s;
    string target = "zdz";
    cout << s.alphabetBoardPath(target) << endl;
}

