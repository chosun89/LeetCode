#ifndef STRINGSPLIT_H
#define STRINGSPLIT_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter) {
    istringstream iss(str);
    string token;
    vector<string> res;

    while (getline(iss, token, delimiter)) {
        res.push_back(token);
    }

    return res;
}


#endif
