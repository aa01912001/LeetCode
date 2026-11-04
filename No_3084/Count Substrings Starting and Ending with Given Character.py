class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        count = s.count(c)
        return count * (count - 1) // 2 + count