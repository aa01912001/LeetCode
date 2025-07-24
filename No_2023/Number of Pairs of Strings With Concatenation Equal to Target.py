class Solution:
    def numOfPairs(self, nums: List[str], target: str) -> int:
        freqs = Counter(nums)
        ans = 0
        
        for num in nums:
            if target.startswith(num):
                postfix = target[len(num):]
                if postfix in freqs:
                    ans += freqs[postfix]
                    if num == postfix:
                        ans -= 1 
        
        return ans