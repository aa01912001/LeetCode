class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        stack = []
        n = len(nums)
        
        for i in range(n):
            if not stack or nums[i] < nums[stack[-1]]:
                stack.append(i)
        
        ans = 0
        for j in range(n-1, -1, -1):
            while stack and nums[j] >= nums[stack[-1]]:
                ans = max(ans, j - stack[-1])
                stack.pop()
        
        return ans