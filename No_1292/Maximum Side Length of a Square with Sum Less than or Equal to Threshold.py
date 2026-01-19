class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        rows, cols = len(mat), len(mat[0])

        # prefix[i][j] = sum of submatrix (0,0) to (i-1,j-1)
        prefix = [[0] * (cols + 1) for _ in range(rows + 1)]
        for i in range(rows):
            for j in range(cols):
                prefix[i + 1][j + 1] = (
                    prefix[i][j + 1]
                    + prefix[i + 1][j]
                    - prefix[i][j]
                    + mat[i][j]
                )

        def square_sum(r: int, c: int, side: int) -> int:
            return (
                prefix[r][c]
                - prefix[r - side][c]
                - prefix[r][c - side]
                + prefix[r - side][c - side]
            )

        left, right = 1, min(rows, cols)
        best = 0

        while left <= right:
            side = (left + right) // 2
            exists_valid_square = False

            for i in range(side, rows + 1):
                for j in range(side, cols + 1):
                    if square_sum(i, j, side) <= threshold:
                        exists_valid_square = True
                        break
                if exists_valid_square:
                    break

            if exists_valid_square:
                best = side
                left = side + 1
            else:
                right = side - 1

        return best