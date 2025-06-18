class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()

        ret = []
        for i in range(len(nums) // 3):
            start = i * 3
            if nums[start+2] - nums[start] > k:
                return []
            ret.append(nums[start:start+3])
        
        return ret