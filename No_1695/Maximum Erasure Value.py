class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        seen = set()
        left = 0
        cur_sum = 0
        ans = 0

        for right in range(len(nums)):
            while nums[right] in seen:
                seen.remove(nums[left])
                cur_sum -= nums[left]
                left += 1

            seen.add(nums[right])
            cur_sum += nums[right]
            ans = max(ans, cur_sum)

        return ans