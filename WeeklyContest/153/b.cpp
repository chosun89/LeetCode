#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
	vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	bool is_leap(int year) {
    if (year % 4 != 0) return false;
    else if (year % 100 != 0) return true;
    else if (year % 400 != 0) return false;
    else return true
	}

	string dayOfTheWeek(int day, int month, int year) {

    int total_days = 0;
    for (int i = 1971; i < year; i++) {
      if (is_leap(i))
        total_days += 366;
      else
        total_days += 365;
    }

    for (int i = 1; i < month; i++) {
      total_days += months[i-1];
      if (i == 2 && is_leap(year))
        total_days += 1;
    }

    total_days += day;
    total_days += (5 - 1);

    return days[(total_days % 7)];
	}
};

int main() {
  Solution s;
  cout << s.dayOfTheWeek(29,2,2016) << endl;

}
