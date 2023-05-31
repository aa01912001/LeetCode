題號: 1269. Number of Ways to Stay in the Same Place After Some Steps
難度: Hard

## 問題描述
You have a pointer at index `0` in an array of size `arrLen`. At each step, you can move 1 position to the left, 1 position to the right in the array, or stay in the same place (The pointer should not be placed outside the array at any time).

Given two integers `steps` and `arrLen`, return the number of ways such that your pointer is still at index `0` after **exactly** `steps` steps. Since the answer may be too large, return it **modulo** `10^9 + 7`.

**Example 1:**
```
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay
```
**Constraints:**

- `1 <= steps <= 500`
- `1 <= arrLen <= 10^6`

## 解決思路
此題可以利用DP的策略來求解。

我們另`dp[i][j]`為剩餘`i` steps時，於index `j`的解。

我們可以輕易地寫出此DP的狀態轉移式為:

`dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]`

最後只需要返回`dp[steps][0]`即可。

因為我們發現在求第`i`列的dp陣列時只需要用到第`i-1`列的dp陣列，因此在程式中我們可以簡化為兩個一維陣列以將空間複雜度降為O(n)。