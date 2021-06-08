題號: 1254. Number of Closed Islands

難度: Medium

## 問題描述

Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An island is a maximal 4-directionally connected group of `0s` and a closed island is an island **totally** (all left, top, right, bottom) surrounded by `1s`.

Return the number of closed islands.

Example 1:

![image alt](https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png)

```
Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
```

Constraints:

- `1 <= grid.length, grid[0].length <= 100`
- `0 <= grid[i][j] <=1`

---
## 解決思路

此題我們可以透過DFS策略來將為0的位置進行深度搜尋，同時對於走過的0標註為-1，如此就可以將一個連通的component都進行遍歷。而只要發現該component有位於邊界的0則代表該component不是closed。