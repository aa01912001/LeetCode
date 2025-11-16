class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        idx1 = idx2 = 0
        if nums[0] > nums[1]:
            idx2 = 1
            
        for i in range(1, len(nums)):
            if nums[i] > nums[idx1]:
                idx2 = idx1
                idx1 = i
            elif nums[i] > nums[idx2]:
                idx2 = i

        
        return -1 if nums[idx2] * 2 > nums[idx1] else idx1
