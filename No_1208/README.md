題號: 1208. Get Equal Substrings Within Budget
難度: Medium

## 問題描述

You are given two strings `s` and `t` of the same length and an integer `maxCost`.

You want to change `s` to `t`. Changing the `ith` character of `s` to `ith` character of `t` costs `|s[i] - t[i]|` (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of `s` that can be changed to be the same as the corresponding substring of `t` with a cost less than or equal to `maxCost`. If there is no substring from `s` that can be changed to its corresponding substring from `t`, return `0`.

**Example 1:**
```
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `t.length == s.length`
- `0 <= maxCost <= 10^6`
- `s` and `t` consist of only lowercase English letters.


---
## 解決思路

此題我們首先可以計算`s`與`t`每個字元成本差的prefix sum，如：

s = "abcd"
t = "bcdf"

prefixSum = [0, 1, 2, 3, 5] (我們將最前面加上0以便後續操作)

針對此prefix sum我們令`i`、`j`指向索引0，並執行sliding window操作以找出成本小於`maxCost`之最長的子字串(`prefixSum[j]-prefixSum[i]`為子字串之成本)。

若當前子字串之成本大於`maxCost`，則`i++`降低成本，否則`j++`考慮更長子字串的可能性。

過程中，我們只要記錄最大的合法子字串長度即可。