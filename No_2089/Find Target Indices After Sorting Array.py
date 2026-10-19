class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        less_count = target_count = 0
        for num in nums:
            if num < target:
                less_count += 1
            elif num == target:
                target_count += 1
        
        return [i for i in range(less_count, less_count + target_count)]