class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n1, n2 = len(nums1), len(nums2)
        dp = [[float('-inf')] * n2 for _ in range(n1)]

        for i in range(n1):
            for j in range(n2):
                pair = nums1[i] * nums2[j]

                best = pair
                if i > 0 and j > 0:
                    best = max(best, pair + dp[i-1][j-1])
                if i > 0:
                    best = max(best, dp[i-1][j])
                if j > 0:
                    best = max(best, dp[i][j-1])

                dp[i][j] = best

        return dp[-1][-1]
