題號: 70. Climbing Stairs
難度: Easy

## 問題描述

You are climbing a staircase. It takes `n` steps to reach the top.

Each time you can either climb `1` or `2` steps. In how many distinct ways can you climb to the top?

**Example 1:**
```
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
```
**Constraints:**

- `1 <= n <= 45`

---
## 解決思路

此題對於`n`來說只有可能從`n-1`與`n-2`的地方爬到，因此其方式個數為`dp[n-1]+dp[n-2]`，因此對於每個前面的階層來說，我們也都能以同樣的方式計算出來。