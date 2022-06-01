題號: 1638. Count Substrings That Differ by One Character
難度: Medium

## 問題描述

Given two strings `s` and `t`, find the number of ways you can choose a non-empty substring of `s` and replace a **single character** by a different character such that the resulting substring is a substring of `t`. In other words, find the number of substrings in `s` that differ from some substring in `t` by **exactly** one character.

For example, the underlined substrings in `"computer"` and `"computation"` only differ by the `'e'`/`'a'`, so this is a valid way.

Return the number of substrings that satisfy the condition above.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**
```
Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.
```
**Constraints:**

- `1 <= s.length, t.length <= 100`
- `s` and `t` consist of lowercase English letters only.

---
## 解決思路

此題我們需要準備兩個DP陣列如下：

1. `vector<vector<int>> same`

    其中`same[i][j]`代表包含`s[i]`與`t[j]`為最後字元，完全相同的共同子字串長度。

    因此，我們可以歸納出狀態轉移式如下：
    `same[i][j] = 1 + same[i-1][j-1], if s[i] == t[j]`
    `same[i][j] = 0, if s[i] != t[j]`
    
2. `vector<vector<int>> diff`

    其中`diff[i][j]`代表包含`s[i]`與`t[j]`為最後字元，且只有其中一個字元有差異的子字串長度。
    
    同樣地，，我們可以歸納出狀態轉移式如下：
    `diff[i][j] = diff[i-1][j-1], if s[i] == t[j]`
    `diff[i][j] = 1 + same[i-1][j-1], if s[i] != t[j]`
    
之後我們只需要將所有`diff[i][j]`相加即為最終答案。
