class Solution:
    def numTeams(self, rating: List[int]) -> int:
        n = len(rating)
        ret = 0
        
        for i in range(n):
            l = sum(1 for j in range(i) if rating[j] < rating[i])
            r = sum(1 for j in range(i+1, n) if rating[j] > rating[i])
            
            ret += l * r + (i - l) * (n - i - 1 - r) 
            
        return ret