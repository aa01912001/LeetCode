class Solution:
    def maximizeGreatness(self, nums: List[int]) -> int:
        nums.sort()
        cur = 0
        for i in range(1, len(nums)):
            if nums[i] > nums[cur]:
                cur += 1

        return cur