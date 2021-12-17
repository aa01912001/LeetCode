題號: 1155. Number of Dice Rolls With Target Sum

難度: Medium

## 問題描述

You have `n` dice and each die has `k` faces numbered from `1` to `k`.

Given three integers `n`, `k`, and `target`, return the number of possible ways (out of the `k^n` total ways) to roll the dice so the sum of the face-up numbers equals `target`. Since the answer may be too large, return it **modulo** `10^9 + 7`.

**Example 1:**
```
Input: n = 1, k = 6, target = 3
Output: 1
Explanation: You throw one die with 6 faces.
There is only one way to get a sum of 3.
```

**Constraints:**

- `1 <= n, k <= 30`
- `1 <= target <= 1000`.

---
## 解決思路

此題可利用DP的策略來考慮第`n`個骰子在當前不同的`target`中，各有幾種組合，程式中，我們令`dp[i][t]`為第`i+1`個骰子於`target`為`t`之解，而dp的狀態轉移式如下:

`dp[i][t+j] = dp[i][t+j] + dp[i-1][t];`
其中，`j`為`1~k`

最後只要返回`dp[n-1][target]`即可。
