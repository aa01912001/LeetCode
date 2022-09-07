題號: 338. Counting Bits
難度: Easy

## 問題描述

Given an integer `n`, return an array `ans` of length `n + 1` such that for each `i` (`0 <= i <= n`), `ans[i]` is the **number of** `1`**'s** in the binary representation of `i`.

**Example 1:**
```
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
```
**Constraints:**

- `0 <= n <= 10^5`

---
## 解決思路

此題我們可透過DP的策略，利用之前計算過的解答來計算當前數字的解。對於`i`來說，其binary 1個數為`i & (i - 1)`的個數+1，因此我們便可輕易計算出來