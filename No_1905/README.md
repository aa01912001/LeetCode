題號: 1905. Count Sub Islands
難度: Medium

## 問題描述

You are given two `m x n` binary matrices `grid1` and `grid2` containing only `0`'s (representing water) and `1`'s (representing land). An **island** is a group of `1`'s connected **4-directionally** (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in `grid2` is considered a **sub-island** if there is an island in `grid1` that contains **all** the cells that make up **this** island in `grid2`.

Return the **number** of islands in `grid2` that are considered **sub-islands**.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/06/10/test1.png)
```
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
```
**Constraints:**

- `m == grid1.length == grid2.length`
- `n == grid1[i].length == grid2[i].length`
- `1 <= m, n <= 500`
- `grid1[i][j]` and `grid2[i][j]` are either `0` or `1`.

---
## 解決思路

此題只需要使用DFS策略來將`grid2`所有連續的1進行遍歷，同時判斷當前的1是否在`grid1`相同的位置上也為1，否則此塊連續的陸地不合法，因此不能算進解答中。
