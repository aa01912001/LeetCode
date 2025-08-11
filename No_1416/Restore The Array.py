class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        MOD = 10**9 + 7
        max_len = len(str(k))

        @cache
        def recursion(idx):
            if idx == len(s):
                return 1
            if s[idx] == '0':
                return 0

            total = 0
            num = 0
            for i in range(idx, min(len(s), idx + max_len)):
                num = num * 10 + int(s[i])
                if num > k:
                    break
                total = (total + recursion(i + 1)) % MOD

            return total

        return recursion(0)