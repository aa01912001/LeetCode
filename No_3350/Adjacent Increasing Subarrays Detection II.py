class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        ans = 0
        prev_len = curr_len = 1
        n = len(nums)

        for i in range(1, n):
            if nums[i] > nums[i-1]:
                curr_len += 1
            else:
                ans = max(ans, curr_len // 2)
                ans = max(ans, min(prev_len, curr_len))
                prev_len = curr_len
                curr_len = 1

        ans = max(ans, curr_len // 2)
        ans = max(ans, min(prev_len, curr_len))

        return ans
