class Solution:
    def findSmallestInteger(self, nums: List[int], value: int) -> int:
        count = defaultdict(int)
        
        for i in range(value):
            count[i] = 0
            
        for num in nums:
            count[num % value] += 1
            
        min_item = min(count.items(), key=lambda item: (item[1], item[0]))
        
        return min_item[0] + (value * min_item[1])