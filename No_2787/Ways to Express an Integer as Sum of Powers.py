class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 10**9 + 7
        powers = []
        base = 1
        while True:
            p = base ** x
            if p > n:
                break
            powers.append(p)
            base += 1
        
        dp = [0] * (n + 1)
        dp[0] = 1
        for p in powers:
            for t in range(n, p-1, -1):
                dp[t] = (dp[t] + dp[t-p]) % MOD

        return dp[n]