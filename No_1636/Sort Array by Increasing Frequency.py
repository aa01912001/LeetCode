class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        freq = Counter(nums)
        nums.sort(key=lambda num: (freq[num], -num))
        
        return nums
        