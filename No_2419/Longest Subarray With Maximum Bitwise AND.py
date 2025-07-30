class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        max_val = max(nums)
        ans = curr = 0

        for num in nums:
            if num == max_val:
                curr += 1
                ans = max(ans, curr)
            else:
                curr = 0
        
        return ans
                
