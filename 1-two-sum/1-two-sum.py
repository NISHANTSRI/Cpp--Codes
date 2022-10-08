class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        tmp = {}
        for i,num in enumerate(nums):
            if target-num in tmp:
                return [i,tmp[target-num]]
            
            tmp[num] = i
        return [-1,-1]
        