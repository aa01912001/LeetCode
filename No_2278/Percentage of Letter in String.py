class Solution:
    def percentageLetter(self, s: str, letter: str) -> int:
        return 100 * sum(1 for c in s if c == letter) // len(s)