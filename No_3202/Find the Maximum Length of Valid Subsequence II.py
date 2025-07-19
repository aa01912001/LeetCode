class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        ans = 0
        dp = [[0] * k for i in range(k)]
        
        for num in nums:
            remainder = num % k
            for i in range(k):
                dp[i][remainder] = dp[remainder][i] + 1
                ans = max(ans, dp[i][remainder])

        return ans