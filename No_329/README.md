題號: 329. Longest Increasing Path in a Matrix
難度: Hard

## 問題描述

Given an `m x n` integers `matrix`, return the length of the longest increasing path in `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** (i.e., wrap-around is not allowed).

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)
```
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
```
**Constraints:**

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 200`
- `0 <= matrix[i][j] <= 2^31 - 1`

---
## 解決思路

此題中，我們可利用backtracking的方式來走訪每條可能的路徑，過程中我們採用memorization的方式來記錄每一格曾經解過的答案以避免重複走訪計算，另一方面，我們也另外記錄目前所走訪的最長路徑長度即可。