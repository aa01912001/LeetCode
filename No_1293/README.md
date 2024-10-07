題號: 1293. Shortest Path in a Grid with Obstacles Elimination
難度: Hard

## 問題描述
You are given an `m x n` integer matrix `grid` where each cell is either `0` (empty) or `1` (obstacle). You can move up, down, left, or right from and to an empty cell in **one step**.

Return the minimum number of **steps** to walk from the upper left corner `(0, 0)` to the lower right corner `(m - 1, n - 1)` given that you can eliminate **at most** `k` obstacles. If it is not possible to find such walk return `-1`.

**Example 1:**
![short1-grid](https://hackmd.io/_uploads/HyKkYJZkyg.jpg)
```
Input: grid = [[0,0,0],[1,1,0],[0,0,0],[0,1,1],[0,0,0]], k = 1
Output: 6
Explanation: 
The shortest path without eliminating any obstacle is 10.
The shortest path with one obstacle elimination at position (3,2) is 6. Such path is (0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2) -> (3,2) -> (4,2).
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 40`
- `1 <= k <= m * n`
- `grid[i][j]` is either `0` **or** `1`.
- `grid[0][0] == grid[m - 1][n - 1] == 0`


**解決思路:**
此題我們可以只需要透過BFS的方式來走訪每個cell，同時我們需要紀錄每個cell是否拜訪過，以及當時拜訪所剩餘的k個數。

若我們走到`grid[i][j]`，就需要查看當前所剩餘的`k`是否比曾經走訪時的`k`來的小，若是，則代表不需要再次經過此cell，因為當初已經是更好的路徑。

一旦我們走到目的地，即可返回路徑部署，也就是BFS迭代了幾次擴展。
