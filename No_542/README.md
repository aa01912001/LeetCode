題號: 542. 01 Matrix

難度: Medium

## 問題描述

Given an `m x n` binary matrix `mat`, return the distance of the nearest `0` for each cell.

The distance between two adjacent cells is `1`.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

**Constraints:**

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 10^4`
- `1 <= m * n <= 10^4`
- `mat[i][j]` is either `0` or `1`.
- There is at least one `0` in `mat`.


---
## 解決思路

此題可利用dp的策略來算出每一格距離0的最短距離。我們需要執行兩次遍歷，第一次從`mat`的左上到右下來找出最短距離。其中:

`dp[i][j] = 0, 當mat[i][j] = 0;`
`dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1, else;`

如此即可得到從上面一格或左邊一格到0所距離最近的距離。

然而最近距離也可能是來自於下方一格或左邊一格，所以我們需要對`mat`進行右下到左上的第二次遍歷。其中:

`dp[i][j] = 0, 當mat[i][j] = 0;`
`dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1]) + 1), else;`

如此我們就考慮了每一格的解是來自四方的可能性，因此求出最後的解答矩陣。