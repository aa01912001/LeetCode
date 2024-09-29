class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        count = 0
        hset = set()
        
        for num in rolls:
            hset.add(num)
            if len(hset) == k:
                hset.clear()
                count += 1
                
        return count + 1