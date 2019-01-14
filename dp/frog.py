class Solution:
    dp = {}
    def canCross(self, stones, pos = 0, k = 0):
        """
        :type stones: List[int]
        :rtype: bool
        """
        # the pos is < 1100, so it is small enough for the first 11 bits of an integer
        # the remaining 21 bits are used for k = distance, which also never exceeds 1100
        key = (k << 11) | pos
        
        if (key in self.dp) :
            return self.dp[key]
        
        i = pos 
        for stone in stones[pos + 1:] :
          gap = stone - stones[pos]
          i+=1
          if (gap < k - 1) : 
            continue
          if (gap > k + 1) :
            self.dp[key] = False
            return False
          # else if gap == (k+1 || k-1), recurse
          if (self.canCross(stones, i, gap)) :
            self.dp[key] = True
            return True
        
        self.dp[key] = (pos == (len(stones) - 1))
        return self.dp[key]

s = Solution()
stones = [0,1,2,3,4,8,9,11]
print(s.canCross(stones))
