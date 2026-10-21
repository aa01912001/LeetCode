class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)

        is_sorted = True
        for i in range(1, n):
            if s[i] < s[i - 1]:
                is_sorted = False
                break

        if is_sorted:
            return 0

        if n == 2:
            return -1

        min_val = min(s)
        max_val = max(s)

        if s[0] == min_val or s[-1] == max_val:
            return 1

        for i in range(1, n-1):
            if min_val == s[i] or max_val == s[i]:
                return 2

        return 3

        