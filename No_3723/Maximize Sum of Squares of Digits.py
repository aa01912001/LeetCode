class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ''

        ans = []
        for _ in range(num):
            d = min(9, sum)
            ans.append(str(d))
            sum -= d

        return ''.join(ans)