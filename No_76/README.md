題號: 76. Minimum Window Substring
難度: Hard

## 問題描述
Given two strings `s` and `t` of lengths `m` and `n` respectively, return the **minimum window substring** of `s` such that every character in `t` (**including duplicates**) is included in the window. If there is no such substring, return the empty string `""`.

The testcases will be generated such that the answer is **unique**.

**Example 1:**
```
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
```

**Constraints:**

- `m == s.length`
- `n == t.length`
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

**Follow up**: Could you find an algorithm that runs in `O(m + n)` time?

## 解決思路
此題為典型的sliding window題，我們只需要利用hash table來記錄當前window內的字元個數即可。

首先我們先統計`t`中每個字元的個數。

之後對`s`做sliding window。
在每回合中，首先先將`s[right]`的count數減1，並判斷數量是否大於等於0，若是的話代表該字元是我們需要的，因此將`numOfIncludedChar`(表示當前涵蓋的必要字元個數)加1。

接著若`numOfIncludedChar == t.size()`代表當前window涵蓋了所有必要字元，因此我們更新解答後，將`left`縮進以尋求更短的可能性。
