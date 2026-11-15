class Solution:
    def numOfSubarrays(self, arr: list[int]) -> int:
        MOD = int(1e9 + 7)
        dp_odd = dp_even = ans = 0
        
        for num in arr:
            if num & 1:
                dp_odd, dp_even = (dp_even + 1) % MOD, dp_odd
            else:
                dp_even = (dp_even + 1) % MOD
            
            ans = (ans + dp_odd) % MOD
            
        return ans