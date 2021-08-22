題號: 567. Permutation in String

難度: Medium

## 問題描述

Given two strings `s1` and `s2`, return `true` if `s2` contains a permutation of `s1`, or `false` otherwise.

In other words, return `true` if one of `s1`'s permutations is the substring of `s2`.

**Example 1:**

```
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
```

**Constraints:**

- '1 <= s1.length, s2.length <= 10^4'
- `s1` and `s2` consist of lowercase English letters.
---
## 解決思路

此題只需利用`vector<int>`來記錄`s1`字元出現頻率，之後只要去比較`s2`長度跟`s1`一樣的子字串字元出現頻率是否與`s1`一樣即可。

