class Solution {
public:
  // character to digit mapping and the inverse
	// (if you want better performance: use array instead of unordered_map)
  unordered_map<char, int> c2i;
  unordered_map<int, char> i2c;

	// limit: length of result
  int limit;

	// idx: index of digit in a word, widx: index of a word in word list, sum: summation of all word[idx]  
  bool helper(vector<string>& words, string& result, int idx, int widx, int sum) {
    // base case 1: if index is one past the end of result, return true if there is no carry
    if (idx == limit) {
      return sum == 0;
    }

    // base case 2: all words have been summed for current idx
    if (widx == words.size()) 
    {
      // if the result[idx] not been assigned an int yet
      if (c2i.count(result[idx]) == 0 && i2c.count(sum%10) == 0) 
      {
        if (sum%10 == 0 && idx+1 == limit) // Avoid leading zero in result
          return false;
        // since result[idx] has not been assigned an int, assign to it sum%10
        c2i[result[idx]] = sum%10;
        i2c[sum%10] = result[idx];
        // recurse from top
        bool tmp = helper(words, result, idx+1, 0, sum/10);
        c2i.erase(result[idx]);
        i2c.erase(sum%10);
        return tmp;
      } 
      else if (c2i.count(result[idx]) && c2i[result[idx]] == sum%10) 
      {
        // if valid (result[idx] has been assigned and matches sum%10), recurse from top
        return helper(words, result, idx+1, 0, sum/10);
      } 
      else 
      {
        return false;
      }
    }

    // if word[widx] length less than digit, ignore and go to next word
    if (idx >= words[widx].length()) {
      return helper(words, result, idx, widx+1, sum);
    }

    // if word[widx][idx] already mapped to a value
    if (c2i.count(words[widx][idx])) {
      // if the current character is an MSD and maps to 0, reject (no leading zeros)
      if (idx == words[widx].length()-1 && words[widx].length() > 1 && c2i[words[widx][idx]] == 0)
        return false;
      return helper(words, result, idx, widx+1, sum+c2i[words[widx][idx]]);
    }

    // if word[widx][idx] not mapped to a value yet
    for (int i = 0; i < 10; i++) {
      // skip the leading zeros case
      if (idx == words[widx].length()-1 && i == 0 && words[widx].length() > 1) continue;
      // skip already mapped digits
      if (i2c.count(i)) continue;

      c2i[words[widx][idx]] = i;
      i2c[i] = words[widx][idx];
      // try a new char to int pairing and recurse on next word
      bool tmp = helper(words, result, idx, widx+1, sum+i);
      c2i.erase(words[widx][idx]);
      i2c.erase(i);
      if (tmp) return true;
    }
    return false;
  }

    bool isSolvable(vector<string>& words, string result) {
      this->limit = result.length();
      for (auto &w: words) 
        if (w.length() > limit) 
          return false;

      for (auto& w : words) 
        reverse(w.begin(), w.end());
      reverse(result.begin(), result.end());

      return helper(words, result, 0, 0, 0);
    }
};
