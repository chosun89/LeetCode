class Solution:
    def maxRotateFunction(self, A):
      sum = 0

      F = S = 0
      n = len(A)
      for i, a in enumerate(A) :
        F += i * a 
        S += a 

      maxi = F
      for a in reversed(A) :
        F = F + S - n * a
        maxi = max(maxi,F)

      return maxi 

s = Solution()
A = [4,3,2,6]
print(s.maxRotateFunction(A))
