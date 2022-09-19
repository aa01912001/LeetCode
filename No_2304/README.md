題號: 2304. Minimum Path Cost in a Grid
難度: Medium

## 問題描述

You are given a **0-indexed** `m x n` integer matrix `grid` consisting of **distinct** integers from `0` to `m * n - 1`. You can move in this matrix from a cell to any other cell in the **next** row. That is, if you are in cell `(x, y)` such that `x < m - 1`, you can move to any of the cells `(x + 1, 0), (x + 1, 1), ..., (x + 1, n - 1)`. **Note** that it is not possible to move from cells in the last row.

Each possible move has a cost given by a **0-indexed** 2D array `moveCost` of size `(m * n) x n`, where `moveCost[i][j]` is the cost of moving from a cell with value `i` to a cell in column `j` of the next row. The cost of moving from cells in the last row of `grid` can be ignored.

The cost of a path in `grid` is the **sum** of all values of cells visited plus the **sum** of costs of all the moves made. Return the **minimum** cost of a path that starts from any cell in the **first** row and ends at any cell in the **last** row.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2022/04/28/griddrawio-2.png)
```
[14,3]]
Output: 17
Explanation: The path with the minimum possible cost is the path 5 -> 0 -> 1.
- The sum of the values of cells visited is 5 + 0 + 1 = 6.
- The cost of moving from 5 to 0 is 3.
- The cost of moving from 0 to 1 is 8.
So the total cost of the path is 6 + 3 + 8 = 17.
```
**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `2 <= m, n <= 50`
- `grid` consists of distinct integers from `0` to `m * n - 1`.
- `moveCost.length == m * n`
- `moveCost[i].length == n`
- `1 <= moveCost[i][j] <= 100`

---
## 解決思路

此題我們以DP策略來記錄每一個cell的最佳路徑，因此我們準備一個dp陣列如下:

`vector<vector<int>> dp(m, vector<int>(n, INT_MAX))`

接著我們初始化第一層(`dp[0][i]`)為自身的cell value(`grid[0][i]`)

對於之後的每一個cell(`dp[i][j]`)，我們可以以前一層的每一個cell之dp最佳值+當前之cell value(`grid[i][j]`)來進行dp更新，其狀態轉移式如下:

`dp[i][j] = min(dp[i][j], grid[i][j]+dp[i-1][k]+moveCost[grid[i-1][k]][j])`

其中`k`為0~n-1之值

如此，我們依序取得每一個cell的dp最佳值後，只要取出最後一層的最小dp值即為**minimum Path Cost**。
