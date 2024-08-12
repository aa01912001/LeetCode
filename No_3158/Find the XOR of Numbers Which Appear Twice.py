class Solution:
    def duplicateNumbersXOR(self, nums: List[int]) -> int:
        ret = 0
        counter = Counter(nums)
        for num, count in counter.items():
            if count == 2:
                ret ^= num
            
        return ret