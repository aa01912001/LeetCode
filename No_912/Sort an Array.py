class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        heapq.heapify(nums)
        
        ret = []
        for _ in range(len(nums)):
            ret.append(heapq.heappop(nums))
            
        return ret