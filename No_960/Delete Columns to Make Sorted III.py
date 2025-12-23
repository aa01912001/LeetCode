class Solution:
    def minDeletionSize(self, strs: List[str]) -> int: 
        num_rows = len(strs)
        num_cols = len(strs[0])
        
        # dp[c] stores the maximum number of columns we can keep 
        # ending at column 'c' such that every row remains lexicographically sorted.
        dp = [1] * num_cols
        
        for c in range(1, num_cols):
            for prev in range(c):
                if all(strs[r][prev] <= strs[r][c] for r in range(num_rows)):
                    dp[c] = max(dp[c], dp[prev] + 1)
        
        max_kept_cols = max(dp)
        return num_cols - max_kept_cols