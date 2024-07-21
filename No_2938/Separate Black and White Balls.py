class Solution:
    def minimumSteps(self, s: str) -> int:
        n = len(s)
        ret = 0
        steps = 0
        
        for i in range(n):
            if s[i] == '0':
                ret += steps
            else:
                steps += 1
                
        return ret