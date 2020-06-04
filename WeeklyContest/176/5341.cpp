#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> st;
    vector<int> st1;
    int cnt;
    ProductOfNumbers() {
        st.push_back(1);
        st1.push_back(1);
        cnt = 0;
    }

    void add(int num) {
        st.push_back(st[cnt] * num);
        if (num == 0) {
            st1.push_back(st1[cnt] * 1);
        } else {
            st1.push_back(st1[cnt] * num);
        }
        cnt++;
    }

    int getProduct(int k) {
        if (st[cnt - k] == 0) {
            return st1[cnt] / st1[cnt - k];
        } else {
            return st[cnt] / st[cnt - k];
        }
    }
};

int main() {
  ProductOfNumbers* obj = new ProductOfNumbers();
  obj->add(3);
  obj->add(0);
  obj->add(2);
  obj->add(5);
  obj->add(4);
  cout << obj->getProduct(2) << endl;

}

