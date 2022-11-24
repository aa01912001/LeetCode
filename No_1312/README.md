題號: 1312. Minimum Insertion Steps to Make a String Palindrome
難度: Hard

## 問題描述

Given a string `s`. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make `s` palindrome.

A **Palindrome String** is one that reads the same backward as well as forward.

**Example 1:**
```
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

---
## 解決思路

此題我們以DP的方式來找出最佳解，其中`dp[i][j]`代表`s[i]~s[j]`字串之解，我們考慮一個字串如下:

`a1 a2 **...** b1 b2`，其中`**...**`為任意字元組成之子字串。

針對`a1` ~ `b2`之字串，其可能的最小解答值來自:

1. `a1 a2 **...** b1` 之解答值 + 1(最左邊補`b2`)
2. `a2 **...** b1 b2` 之解答值 + 1(最右邊補`a1`)
3. `a2 **...** b1` 之解答值(若`a1 == ab`)
4. `a2 **...** b1` 之解答值 + 2(若`a1 != ab`，則左邊補`b2`，右邊補`a1`)

根據上述四種情況我們可以使用一個二維的DP陣列來找出`dp[0][n]`之最終值，在執行迴圈時，我們以左上到右下的順序依序找出local optimal value，另外，整個DP的狀態轉移式如下:

- `dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1, dp[i+1][j-1]), if s[i] == s[j]`
- `dp[i][j] = min(dp[i+1][j] + 1, dp[i][j-1] + 1, dp[i+1][j-1] + 2), if s[i] != s[j]`