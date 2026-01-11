class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1 or numRows >= len(s):
            return s

        rows = [''] * numRows
        row = 0
        step = 1  # 1 = down, -1 = up

        for ch in s:
            rows[row] += ch

            if row == 0:
                step = 1
            elif row == numRows - 1:
                step = -1

            row += step

        return ''.join(rows)