#include <bits/stdc++.h>
#include <sstream>
#define pb push_back
using namespace std;

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

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& temp) {
      set<string> res;
			sort(temp.begin(), temp.end(),[](string& a, string& b)->bool {
        vector<string> ts = split(a, ',');
        vector<string> ts2 = split(b, ',');
				if (ts[0] == ts2[0])
					return stoi(ts[1]) < stoi(ts2[1]);
				else return ts[0] < ts2[0];
			});
			for (auto s : temp) 
				cout << s << endl;
			cout << endl;
      for (int i = 0; i < temp.size()-1; i++) {
        vector<string> ts = split(temp[i], ',');
        vector<string> ts2 = split(temp[i+1], ',');
        if (ts[0] == ts2[0] && ts[3] != ts2[3] && abs(stoi(ts2[1]) - stoi(ts[1])) <= 60) {
          res.insert(temp[i]);
          res.insert(temp[i+1]);
        }
        if (stoi(ts[2]) > 1000) {
          res.insert(temp[i]);
        }
        if (stoi(ts2[2]) > 1000) {
          res.insert(temp[i+1]);
        }
      }

      vector<string> res2(res.begin(), res.end());
      return res2;
    }
};

int main() {
  Solution s;
  vector<string> trans = {"bob,649,842,prague","alex,175,1127,mexico","iris,164,119,paris","lee,991,1570,mexico","lee,895,1876,taipei","iris,716,754,moscow","chalicefy,19,592,singapore","chalicefy,820,71,newdelhi","maybe,231,1790,paris","lee,158,987,mexico","chalicefy,415,22,montreal","iris,803,691,milan","xnova,786,804,guangzhou","lee,734,1915,prague","bob,836,1904,dubai","iris,666,231,chicago","iris,677,1451,milan","maybe,860,517,toronto","iris,344,1452,bangkok","lee,664,463,frankfurt","chalicefy,95,1222,montreal","lee,293,1102,istanbul","maybe,874,36,hongkong","maybe,457,1802,montreal","xnova,535,270,munich","iris,39,264,istanbul","chalicefy,548,363,barcelona","lee,373,184,munich","xnova,405,957,mexico","chalicefy,517,266,luxembourg","iris,25,657,singapore","bob,688,451,beijing","bob,263,1258,tokyo","maybe,140,222,amsterdam","xnova,852,330,barcelona","xnova,589,837,budapest","lee,152,981,mexico","alex,893,1976,shenzhen","xnova,560,825,prague","chalicefy,283,399,zurich","iris,967,1119,guangzhou","alex,924,223,milan","chalicefy,212,1865,chicago","alex,443,537,taipei","maybe,390,5,shanghai","bob,510,1923,madrid","bob,798,343,hongkong","iris,643,1703,madrid","bob,478,928,barcelona","maybe,75,1980,shanghai","xnova,293,24,newdelhi","iris,176,268,milan","alex,783,81,moscow","maybe,560,587,milan","alex,406,776,istanbul","lee,558,727,paris","maybe,481,1504,munich","maybe,685,602,madrid","iris,678,788,madrid","xnova,704,274,newdelhi","chalicefy,36,1984,paris","iris,749,200,amsterdam","lee,21,119,taipei","iris,406,433,bangkok","bob,777,542,taipei","maybe,230,1434,barcelona","iris,420,1818,zurich","lee,622,194,amsterdam","maybe,545,608,shanghai","xnova,201,1375,madrid","lee,432,520,dubai","bob,150,1634,singapore","maybe,467,1178,munich","iris,45,904,beijing","maybe,607,1953,tokyo","bob,901,815,tokyo","maybe,636,558,milan","bob,568,1674,toronto","iris,825,484,madrid","iris,951,930,dubai","bob,465,1080,taipei","bob,337,593,chicago","chalicefy,16,176,rome","chalicefy,671,583,singapore","iris,268,391,chicago","xnova,836,153,jakarta","bob,436,530,warsaw","alex,354,1328,luxembourg","iris,928,1565,paris","xnova,627,834,budapest","xnova,640,513,jakarta","alex,119,16,toronto","xnova,443,1687,taipei","chalicefy,867,1520,montreal","alex,456,889,newdelhi","lee,166,3,madrid","bob,65,1559,zurich","alex,628,861,moscow","maybe,668,572,mexico","bob,402,922,montreal"};
  vector<string> res = s.invalidTransactions(trans);
  for (auto s : res) cout << s << endl;

}

