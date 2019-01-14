class Solution:
    def isRectangleOverlap(self, rec1, rec2):
        """
        :type rec1: List[int]
        :type rec2: List[int]
        :rtype: bool
        """
        x1,x2,x3,x4,y1,y2,y3,y4 = rec1[0],rec1[2],rec2[0],rec2[2],rec1[1],rec1[3],rec2[1],rec2[3]
        return x1 < x4 and x3 < x2 and y1 < y4 and y3 < y2

s = Solution()
#rec1 = [0,0,2,2]
#rec2 = [1,1,3,3]
#rec1 = [0,0,1,1]
#rec2 = [1,0,2,1]
rec1 = [7,8,13,15]
rec2 = [10,8,12,20]

print(s.isRectangleOverlap(rec1, rec2))
