class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        ret = 0
        prefix_sum = 0
        freq = defaultdict(int)
        freq[0] = 1
        
        for num in nums:
            prefix_sum += num
            ret += freq[prefix_sum-goal]
            freq[prefix_sum] += 1
    
        return ret