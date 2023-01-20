題號: 1139. Largest 1-Bordered Square
難度: Medium

## 問題描述
Given a 2D `grid` of `0`s and `1`s, return the number of elements in the largest square subgrid that has all `1`s on its border, or `0` if such a subgrid doesn't exist in the `grid`.

**Example 1:**
```
Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
Output: 9
```

**Constraints:**

- `1 <= grid.length <= 100`
- `1 <= grid[0].length <= 100`
- `grid[i][j]` is `0` or `1`

---
## 解決思路

此題我們可以利用DP來記錄每個`grid[i][i]`向左及向上的連續最長長度(`dpLeft[i][j]`、`dpUp[i][j]`)。

之後對於每個`grid[i][j]`為1的點，我們可以將之視為方形的右下角，並計算其可能行成的最大方形面積為和。

而對於`grid[i][j]`來說，其可能形成之最大方形邊長為`int minLen = min(dpLeft[i][j-1], dpUp[i-1][j])`，因此之後我們只需要判斷所有`1~minLen`邊長之方形是否有可能形成即可。

