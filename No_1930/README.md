題號: 1930. Unique Length-3 Palindromic Subsequences
難度: Medium

## 問題描述

Given a string `s`, return the number of **unique palindromes of length three** that are a **subsequence** of `s`.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted **once**.

A **palindrome** is a string that reads the same forwards and backwards.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

- For example, `"ace"` is a subsequence of `"abcde"`.

**Example 1:**
```
Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
```
**Constraints:**

- `3 <= s.length <= 10^5`
- `s` consists of only lowercase English letters.

---
## 解決思路

此題我們先以`vector<pair<int, int>>`的結構紀錄每個字母第一次及最後一次出現的索引位置，之後針對每個字母的此區間去使用`unordered_set<char>`來判斷有多少個不同的字母，最後將此set中的元素個數(代表以某個字母為開頭及結尾的**Length-3 Palindromic Subsequence**個數)加至解答中即可。
