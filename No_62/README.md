題號: 62. Unique Paths
難度: Medium

## 問題描述
There is a robot on an `m x n` grid. The robot is initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

Given the two integers `m` and `n`, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to `2 * 10^9`.

**Example 1:**
![](https://hackmd.io/_uploads/By8zjk1yT.png)
```
Input: m = 3, n = 7
Output: 28
```

**Constraints:**

- `1 <= m, n <= 100`.

## 解決思路
透過觀察我們可以知道，對於每一個目的地的前一格一定來自上方或左方，因此我們只需要將上方位置之解加上左方位置之解，就可以得到當前位置的所有可能步數，因此很明顯地，利用DP的方式就可以輕易解決此問題。