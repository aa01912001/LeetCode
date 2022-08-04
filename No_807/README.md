題號: 807. Max Increase to Keep City Skyline
難度: Medium

## 問題描述

There is a city composed of `n x n` blocks, where each block contains a single building shaped like a vertical square prism. You are given a **0-indexed** `n x n` integer matrix `grid` where `grid[r][c]` represents the **height** of the building located in the block at row `r` and column `c`.

A city's **skyline** is the the outer contour formed by all the building when viewing the side of the city from a distance. The **skyline** from each cardinal direction north, east, south, and west may be different.

We are allowed to increase the height of **any number of buildings by any amount** (the amount can be different per building). The height of a `0`-height building can also be increased. However, increasing the height of a building should **not** affect the city's **skyline** from any cardinal direction.

Return the **maximum total sum** that the height of the buildings can be increased by **without** changing the city's **skyline** from any cardinal direction.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/06/21/807-ex1.png)
```
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: The building heights are shown in the center of the above image.
The skylines when viewed from each cardinal direction are drawn in red.
The grid after increasing the height of buildings without affecting skylines is:
gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]
```
**Constraints:**

- `n == grid.length`
- `n == grid[r].length`
- `2 <= n <= 50`
- `0 <= grid[r][c] <= 100`

---
## 解決思路

此題對於每一個block(`grid[i][j]`)來說，其可能影響的範圍只有第`i`列與第`j`行而已，因此我們最大可以將此block中的building增為`min(第i列最大值, 第j行最大值)`，因此，在程式中，我們可將每一列與每一行的最大值記錄起來後，再針對每一個block去計算其可增加的最大高度。
