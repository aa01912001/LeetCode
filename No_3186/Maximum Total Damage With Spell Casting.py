class Solution:
    def maximumTotalDamage(self, power: List[int]) -> int:
        spell_totals = defaultdict(int)
        for num in power:
            spell_totals[num] += num

        spells = sorted(spell_totals.items())
        n = len(spells)
        if n == 1:
            return spells[0][1]

        dp = [0] * n
        dp[0] = spells[0][1]
        dp[1] = max(spells[1][1], dp[0] if spells[1][0] - spells[0][0] <= 2 else dp[0] + spells[1][1])

        for i in range(2, n):
            # Skip the current spell (inherit previous max)
            dp[i] = dp[i-1]

            #  Take the current spell and find the previous non-conflicting spell
            j = i - 1
            while j >= 0 and spells[i][0] - spells[j][0] <= 2:
                j -= 1

            dp[i] = max(dp[i], (dp[j] if j >= 0 else 0) + spells[i][1])

        return dp[-1]