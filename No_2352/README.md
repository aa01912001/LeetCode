題號: 2352. Equal Row and Column Pairs
難度: Medium

## 問題描述
Given a **0-indexed** `n x n` integer matrix `grid`, return the number of pairs `(ri, cj)` such that row `ri` and column `cj` are equal.

A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

**Example 1:**
![](https://i.imgur.com/7Rw19dI.png)
```
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]
```

**Constraints:**

- `n == grid.length == grid[i].length`
- `1 <= n <= 200`
- `1 <= grid[i][j] <= 10^5`

---
## 解決思路
此題可以利用map來儲存每一row的相同array個數，再判判斷每一column array對應的個數並加總即可。