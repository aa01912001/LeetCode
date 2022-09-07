題號: 322. Coin Change
難度: Medium

## 問題描述

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

**Example 1:**
```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```
**Constraints:**

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`

---
## 解決思路

此題對於`amount`來說我們可以從最少的組合數為:
`min(dp[amount-cost[0]], dp[amount-cost[1]], ... , dp[amount-cost[n-1]]) + 1`。

因此對於1~amount數之解答我們也可以透過該公式以DP策略計算出來，但同時我們也要注意`amount-cost[i]`必須大於等於0才能將此情形考慮進去。