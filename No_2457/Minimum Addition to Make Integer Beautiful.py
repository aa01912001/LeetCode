class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        def digit_sum(x: int) -> int:
            return sum(int(c) for c in str(x))

        original_n = n
        base = 1

        while digit_sum(n) > target:
            remainder = (n // base) % 10
            if remainder != 0:
                n += base * (10 - remainder)
            base *= 10

        return n - original_n
