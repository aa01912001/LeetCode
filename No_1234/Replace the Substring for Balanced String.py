class Solution:
    def balancedString(self, s: str) -> int:
        n = len(s)
        target = n // 4
        counter = Counter(s)

        if all(v == target for v in counter.values()):
            return 0

        redundant = {c: counter[c] - target for c in "QWER" if counter[c] > target}

        ans = n
        left = 0

        for right, ch in enumerate(s):
            if ch in redundant:
                redundant[ch] -= 1

            while all(v <= 0 for v in redundant.values()):
                ans = min(ans, right - left + 1)
                if s[left] in redundant:
                    redundant[s[left]] += 1
                left += 1

        return ans
