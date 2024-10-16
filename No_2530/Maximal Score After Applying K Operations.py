class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        max_heap = [-1 * num for num in nums]
        heapq.heapify(max_heap)
        
        ret = 0
        while k != 0:
            num = -1 * heapq.heappop(max_heap)
            ret += num
            heapq.heappush(max_heap, -1 * math.ceil(num / 3))
            k -= 1
            
        return ret