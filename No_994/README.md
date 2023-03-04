題號: 994. Rotting Oranges
難度: Medium

## 問題描述
You are given an `m x n` `grid` where each cell can have one of three values:

- `0` representing an empty cell,
- `1` representing a fresh orange, or
- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return `-1`.

**Example 1:**
![](https://i.imgur.com/XqcjCnA.png)
```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 10`
- `grid[i][j]` is `0`, `1`, or `2`.

---
## 解決思路
此題只需要使用BSF來擴展不新鮮的橘子即可，並在最後判斷是否還存在留有新鮮的橘子。