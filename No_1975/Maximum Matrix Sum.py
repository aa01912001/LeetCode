class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        total_abs_sum = 0
        min_abs = float("inf")
        negative_count = 0

        for row in matrix:
            for val in row:
                abs_val = abs(val)
                total_abs_sum += abs_val
                min_abs = min(min_abs, abs_val)
                if val < 0:
                    negative_count += 1

        if negative_count % 2 == 0:
            return total_abs_sum
        return total_abs_sum - 2 * min_abs
