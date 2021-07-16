題號: 712. Minimum ASCII Delete Sum for Two Strings

難度: Medium

## 問題描述

Given two strings `s1` and `s2`, return the lowest **ASCII** sum of deleted characters to make two strings equal.

**Example 1:**

```
Input: s1 = "sea", s2 = "eat"
Output: 231
Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
```


**Constraints:**

- `1 <= s1.length, s2.length <= 1000`
- `s1` and `s2` consist of lowercase English letters.

---
## 解決思路

此題我們可利用DP的策略來解，其中`DP[i][j]`代表`s1(0:i-1)`與`s2(0:j-1)`的解(**i、j索引值在s1、s2會少一是因為把空字串的情況考慮近DP中**)。

而當考慮`DP[i][j]`時，若發現`s1[i-1] == s2[j-1]`，則表示最後字元需保留，所以將`DP[i][j] = DP[i-1][j-1]`;反之則考慮`s1(0:i-2)與s2(0:j-1)`或`s1(0:i-1)與s2(0:j-2)`之情況。故其狀態轉移式為:

dp[i][j] = dp[i-1][j-1], **if s1[i-1] == s2[j-1]**
dp[i][j] = min(s1[i-1]+dp[i-1][j], s2[j-1]+dp[i][j-1]), **else**

最後返回`dp[m][n]`即可，其中`m = s1.length(), n = s2.length()`



