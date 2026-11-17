class Solution:
    def findScore(self, nums: List[int]) -> int:
        score = 0
        min_heap = [(num, i) for i, num in enumerate(nums)]
        heapq.heapify(min_heap)
        marked = set()

        while min_heap:
            num, i = heapq.heappop(min_heap)
            if i in marked:
                continue
            
            score += num
            marked.update({i, i-1, i+1})

        return score
