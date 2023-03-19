import sys

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        currSum = 0
        maxSum = -1*sys.maxsize
        i = 0
        while i < len(nums):
            currSum += nums[i]
            maxSum = max(maxSum, currSum)
            
            if currSum < 0:
                currSum = 0
            i += 1
        
        return maxSum