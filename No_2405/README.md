題號: 2405. Optimal Partition of String
難度: Medium

## 問題描述

Given a string `s`, partition the string into one or more **substrings** such that the characters in each substring are **unique**. That is, no letter appears in a single substring more than **once**.

Return the **minimum** number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

**Example 1:**
```
Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
```
**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only English lowercase letters.

---
## 解決思路

此題我們可以從頭開始遍歷`s`的每個字元，並採用greedy策略盡量讓每個子字串包含多個字元，因此，我們使用`unordered_set<char>`來紀錄各個子字串當前所包含的字元，一旦發現當前`s[i]`已經出現在set中，就將此set清空並將解答值加1，否則將`s[i]`插入至set中做為當前子字串的一部分。
