題號: 1504. Count Submatrices With All Ones

難度: Medium

## 問題描述

Given an `m x n` binary matrix `mat`, return the number of **submatrices** that have all ones.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/10/27/ones1-grid.jpg)

```
Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
Output: 13
Explanation: 
There are 6 rectangles of side 1x1.
There are 2 rectangles of side 1x2.
There are 3 rectangles of side 2x1.
There is 1 rectangle of side 2x2. 
There is 1 rectangle of side 3x1.
Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
```

**Constraints:**

- `1 <= m, n <= 150`
- `mat[i][j]` is either `0` or `1`.


---
## 解決思路

此題我們利用DP的策略找出所有可能的**Submatrices**，其中`dp[i][j]`儲存包含`mat[i][j]`上方所有連續1的個數。

當我們遍歷到`mat[i][j]`，我們應該向左遍歷所有連續的1，同時去紀錄當前最小`dp[i][t]`，其中`t <= j`，並將當前最小值加入答案中(如此就可以找出所有位於`mat[i][j]`左上方且全為1(包含`mat[i][j]`)的**Submatrices**。











