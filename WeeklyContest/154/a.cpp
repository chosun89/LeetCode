#include <bits/stdc++.h>
#define pb push_back
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
      int alph[26] = {};

      for (char c : text) {
        alph[c - 'a']++;
      }

      int mini = min (alph['l' - 'a'], alph['o' - 'a']);
      if (mini <= 1) return 0;

      int res = min(mini/2, min(alph['a' - 'a'], min(alph['b' - 'a'], alph['n' - 'a'])));

      return res;

      
    }
};

int main() {

  Solution s;
  string text = "krhizmmgmcrecekgyljqkldocicziihtgpqwbticmvuyznragqoyrukzopfmjhjjxemsxmrsxuqmnkrzhgvtgdgtykhcglurvppvcwhrhrjoislonvvglhdciilduvuiebmffaagxerjeewmtcwmhmtwlxtvlbocczlrppmpjbpnifqtlninyzjtmazxdbzwxthpvrfulvrspycqcghuopjirzoeuqhetnbrcdakilzmklxwudxxhwilasbjjhhfgghogqoofsufysmcqeilaivtmfziumjloewbkjvaahsaaggteppqyuoylgpbdwqubaalfwcqrjeycjbbpifjbpigjdnnswocusuprydgrtxuaojeriigwumlovafxnpibjopjfqzrwemoinmptxddgcszmfprdrichjeqcvikynzigleaajcysusqasqadjemgnyvmzmbcfrttrzonwafrnedglhpudovigwvpimttiketopkvqw";

  cout << s.maxNumberOfBalloons(text) << endl;
  

}

