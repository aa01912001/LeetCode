class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        total = nums[0]
        left = 0
        ret = 1
        for right in range(1, len(nums)):
            total += nums[right]
            while total + k < nums[right] * (right - left + 1):
                total -= nums[left]
                left += 1
            ret = max(ret, right - left + 1)
        
        return ret
        