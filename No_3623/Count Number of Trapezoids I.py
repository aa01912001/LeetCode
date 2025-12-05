class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        from collections import Counter
        MOD = 10**9 + 7

        cnt = Counter(y for _, y in points)

        ans = 0
        total = 0
        for c in cnt.values():
            if c > 1:
                p = c * (c - 1) // 2
                ans = (ans + total * p) % MOD
                total += p
        return ans % MOD
