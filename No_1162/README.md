題號: 1162. As Far from Land as Possible
難度: Medium

## 問題描述
Given an `n x n` `grid` containing only values `0` and `1`, where `0` represents water and `1` represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return `-1`.

The distance used in this problem is the Manhattan distance: the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.

**Example 1:**
![](https://hackmd.io/_uploads/HkIrlMkBn.png)
```
Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
```

**Constraints:**

- `n == grid.length`
- `n == grid[i].length`
- `1 <= n <= 100`
- `grid[i][j]` is `0` or `1`

## 解決思路
此題中我們可以知道，對於每一個cell來說，其解一定是來自於上下左右cell中最小值解再加1步，因此我們只需要利用DP的方式來記錄先前計算過的cell即可。另外對於值為1的cell來說，它的DP值為0。

程式中，我們由左上至右下遍歷過一次，再從右下至左上遍歷一次，即可得到每個cell距離陸地的最近距離。