class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        width = nums.count(1)
        ret = length = len(nums)
        
        zeros = nums[:width].count(0)
        for i in range(length):
            ret = min(ret, zeros)
            zeros += nums[(i + width) % length] == 0
            zeros -= nums[i] == 0
            
        return ret