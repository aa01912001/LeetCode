題號: 2684. Maximum Number of Moves in a Grid

難度: Medium

## 問題描述
You are given a **0-indexed** `m x n` matrix `grid` consisting of **positive** integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

- From a cell `(row, col)`, you can move to any of the cells: `(row - 1, col + 1)`, `(row, col + 1)` and `(row + 1, col + 1)` such that the value of the cell you move to, should be **strictly** bigger than the value of the current cell.

Return the **maximum** number of **moves** that you can perform.

**Example 1:**
![yetgriddrawio-10](https://hackmd.io/_uploads/rJ97dxRF1e.png)
```
Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.

```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `2 <= m, n <= 1000`
- `4 <= m * n <= 10^5`
- `1 <= grid[i][j] <= 10^6`


**解決思路:**

此題我們採用DP的方式來判斷當下的`grid[row][col]`是否可以抵達。
其中我們令`dp[row]`為`grid[row][col]`可否抵達的狀態，0的話不行，1則可以，其狀態轉移式如下:


`new_dp[row]` =
 - 1, if `row−1 >= 0` and `grid[row][col] > grid[row−1][col−1]` and `dp[row−1] == 1`
 - 1, if `grid[row][col] > grid[row][col−1]` and `dp[row−1] == 1`
 - 1, if `row+1 < 0` and `grid[row][col] > grid[row+1][col−1]` and `dp[row+1] == 1`
 - 0, else

只要當前行有某一列為1，我們則將解答值加上1即可。