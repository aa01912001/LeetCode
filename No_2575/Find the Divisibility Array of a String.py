class Solution:
    def divisibilityArray(self, word: str, m: int) -> List[int]:
        n = len(word)
        ans = [0] * n
        remainder = 0
        for i in range(n):
            remainder = (10 * remainder + int(word[i])) % m
            if remainder == 0:
                ans[i] = 1

        return ans
