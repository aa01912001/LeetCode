題號: 1593. Split a String Into the Max Number of Unique Substrings
難度: Medium

## 問題描述

Given a string `s`, return the maximum number of unique substrings that the given string can be split into.

You can split string `s` into any list of **non-empty substrings**, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are **unique**.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**
```
Input: s = "ababccc"
Output: 5
Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
```
**Constraints:**

- `1 <= s.length <= 16`
- `s` contains only lower case English letters.

---
## 解決思路

此題我們只需要透過Backtracking策略來對字串進行暴力分解子字串，另外過程中我們使用`unordered_set<string>`的結構來儲存已分解出來的字串，一但在後續出現重複的子字串即停止該分支的進行。
