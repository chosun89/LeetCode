#include <bits/stdc++.h>
using namespace std;

//           [first, last) 
int lower(vector<int> arr, int first, int last, int find) {
  int dist = last - first;
  while (dist > 0) {
    int step = dist / 2;
    int m = first + step;
    if (arr[m] < find) {
      first = ++m;
      dist -= ++step;
    }
    else dist = step;
  }
  return first;
}

//           [first, last) 
int upper(vector<int> arr, int first, int last, int find) {
  int dist = last - first;
  while (dist > 0) {
    int step = dist / 2;
    int m = first + step;
    if (!(find < arr[m])) {
      first = ++m;
      dist -= step+1;
    }
    else dist = step;
  }
  return first;
}

int main() {
  int find = 3;
  //vector<int> arr = {1,1,1,1,1,1,1}; // n = 7
  vector<int> arr = {1,2,3,3,3,4,8}; // n = 7
  auto low = lower_bound(arr.begin(), arr.end(), find);
  auto high = upper_bound(arr.begin(), arr.end(), find);
  cout << "std::lower_bound " <<  low - arr.begin() << endl;
  cout << "std::upper_bound " << high - arr.begin() << endl;
  cout << "lower(): " << lower(arr, 0, 7, find) << endl;
  cout << "upper(): " << upper(arr, 0, 7, find) << endl;

}

