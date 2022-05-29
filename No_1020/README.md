題號: 1020. Number of Enclaves
難度: Medium

## 問題描述

You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.

Return the number of land cells in `grid` for which we cannot walk off the boundary of the grid in any number of **moves**.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg)
```
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
```
**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 500`
- `grid[i][j]` is either `0` or `1`.

---
## 解決思路

此題只需要DFS來遍歷所有連續的1，並記錄其數量，過程中我們利用`bool hasBoundary`這個變數來判斷此塊陸地是否有包含邊界，若結束遞迴後發現其值為false，我們則將回傳之陸地大小值加至解答中。