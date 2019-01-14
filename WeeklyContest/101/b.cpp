#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a)<<endl;i<(b);i++)
#define pb push_back
using namespace std;

class StockSpanner {
public:
    stack< pair<int,int> > st;

    StockSpanner() {
    }
    
    int next(int price) {
      int res = 1;
      while (!st.empty() && st.top().first <= price) {
        res += st.top().second;
        st.pop();
      }
      st.push({price, res});
      return res;
    }
};

int main() {

  StockSpanner s;
  cout<<s.next(100)<<endl;
  cout<<s.next(80)<<endl;
  cout<<s.next(60)<<endl;
  cout<<s.next(70)<<endl;
  cout<<s.next(60)<<endl;
  cout<<s.next(75)<<endl;
  cout<<s.next(85)<<endl;

}

