class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
        nums.sort()
        mid = len(nums) // 2

        if k >= nums[mid]:
            return sum(
                k - num
                for num in nums[mid:]
                if num < k
            )

        else:
            return sum(
                num - k
                for num in nums[mid::-1]
                if num > k
            )