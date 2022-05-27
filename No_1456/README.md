題號: 1456. Maximum Number of Vowels in a Substring of Given Length
難度: Medium

## 問題描述

Given a string `s` and an integer `k`, return the maximum number of vowel letters in any substring of `s` with length `k`.

**Vowel letters** in English are `'a'`, `'e'`, `'i'`, `'o'`, and `'u'`.

**Example 1:**

```
Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
```
**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase English letters.
- `1 <= k <= s.length`

---
## 解決思路

此題只需要利用prefix sum來記錄包含`s[i]`以前的所有母音個數，即可輕易地找出每段長度為`k`的子字串之母音個數，過程中只要不斷更新最大值之解即可。

