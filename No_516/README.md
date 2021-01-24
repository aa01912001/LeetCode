題號: 516. Longest Palindromic Subsequence

難度: Medium

## 問題描述
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:

```
Input: "bbbab"
Output: 4

One possible longest palindromic subsequence is "bbbb".
```

Constraints:
- `1 <= s.length <= 1000`
- `s` consists only of lowercase English letters.


---
## 解決思路
此題相當於將字串`s`與`reverse(s)`解Longest Common Subsequence問題，所以我們可以使用DP來解此題，其狀態轉移式為:

**dp[i][j] = max(dp[i][j-1], dp[i-1][j]), if e1 != e2**
**dp[i][j] = dp[i-1][j-1] + 1, if e1 != e2**