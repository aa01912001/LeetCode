class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda t : t[0] - t[1])

        ret = remaining = 0
        for t in tasks:
            if remaining < t[1]:
                ret += t[1] - remaining
                remaining = t[1]
                
            remaining -= t[0]
                
        return ret
        
        
        