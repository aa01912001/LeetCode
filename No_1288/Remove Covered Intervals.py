class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        
        ret = far = 0
        for _, e in intervals:
            if e > far:
                ret += 1
                far = e
        
        return ret