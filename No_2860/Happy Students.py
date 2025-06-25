class Solution:
    def countWays(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        nums.sort()

        if nums[0] != 0:
            ans += 1

        if nums[-1] < n:
            ans += 1

        for i in range(n-1):
            selected_count = i + 1
            if nums[i] < selected_count < nums[i+1]:
                ans += 1

        return ans