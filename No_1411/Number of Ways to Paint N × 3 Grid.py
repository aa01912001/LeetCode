class Solution:
    def numOfWays(self, n: int) -> int:
        pattern1 = 6  # c1 c2 c3
        pattern2 = 6  # c1 c2 c1
        MOD = 10**9 + 7
        for _ in range(n - 1):
            new_pattern1 = (2 * pattern1 + 2 * pattern2) % MOD
            new_pattern2 = (2 * pattern1 + 3 * pattern2) % MOD
            pattern1, pattern2 = new_pattern1, new_pattern2
        
        return (pattern1 + pattern2) % MOD
            