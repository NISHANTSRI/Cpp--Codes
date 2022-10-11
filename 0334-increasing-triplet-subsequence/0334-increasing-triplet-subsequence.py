import sys
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        c1 = sys.maxsize
        c2 = sys.maxsize
        for i in nums:
            if i <= c1:
                c1 = i
            elif i <= c2:
                c2 = i
            else:
                return True
        
        return False
        