class Solution:
    def minimumLength(self, s: str) -> int:
        counter = Counter(s)
        
        ret = 0
        for key in counter:
            ret += 1 if counter[key] % 2 == 1 else 2
            
        return ret