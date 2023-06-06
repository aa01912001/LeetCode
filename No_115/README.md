題號: 115. Distinct Subsequences
難度: Hard

## 問題描述
Given two strings `s` and `t`, return the number of distinct **subsequences** of `s` which equals `t`.

The test cases are generated so that the answer fits on a 32-bit signed integer.

**Example 1:**
```
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
```
**Constraints:**

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## 解決思路
此題可利用DP的方式來求解，其中:

`dp[i][j]`代表在`s0~sj`中對於`t0~ti`之解的數量。

而該DP的狀態轉移式如下:

- `dp[i][j] = dp[i][j-1] + dp[i-1][j-1], if t[i] == s[j]`

- `dp[i][j] = dp[i][j-1], if t[i] != s[j]`

以例子一來說，`t[3] == s[4]`時，我們想要尋找"rabbb"與"rabb"的解，而此解相當於將
"rabb"和"rab"之解(也就是最後的`b`需匹配)與"rabb"和"rabb"之解(也就是不使用"rabbb"最後的b)的數量加總起來。