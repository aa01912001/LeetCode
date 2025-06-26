class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        ans = binary_value = bit_position = 0
        for i in range(n-1, -1, -1):
            num = int(s[i]) * (1 << bit_position)
            if binary_value + num <= k:
                ans += 1
                binary_value += num
                bit_position += 1

        return ans