class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        squares = sorted(x * x for x in nums)
        n = len(squares)
        m = n // 2

        return sum(squares[m:]) - sum(squares[:m])