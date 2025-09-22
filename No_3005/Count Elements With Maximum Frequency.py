class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        counter = Counter(nums)
        ans = 0
        max_freq = 0
        for freq in counter.values():
            if freq == max_freq:
                ans += freq
            elif freq > max_freq:
                ans = freq
                max_freq = freq
        
        return ans