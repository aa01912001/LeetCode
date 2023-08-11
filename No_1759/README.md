題號: 1759. Count Number of Homogenous Substrings
難度: Medium

## 問題描述
Given a string `s`, return the number of **homogenous** substrings of `s`. Since the answer may be too large, return it **modulo** `10^9 + 7`.

A string is **homogenous** if all the characters of the string are the same.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**
```
Input: s = "abbcccaa"
Output: 13
Explanation: The homogenous substrings are listed as below:
"a"   appears 3 times.
"aa"  appears 1 time.
"b"   appears 2 times.
"bb"  appears 1 time.
"c"   appears 3 times.
"cc"  appears 2 times.
"ccc" appears 1 time.
3 + 1 + 2 + 1 + 3 + 2 + 1 = 13.
```
**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of lowercase letters.

## 解決思路
此題採用two pointer的方式，以`left`、`right`作為連續相同字元的區間。在每回合中我們比較`s[left]`與`s[right]`是否相等。

1. 若`s[left] == s[right]`: 則我們將解答加上`right - left + 1`

2. 若`s[left] != s[right]`: 則我們將解答加上`1`(`s[right]`本身為homogenous substring)，並將`left`指向`right`位置

假設index i ~ index j-1為相同字元
a a a a ... a
若index j同樣為a，則有homogenous substrings如下:

a
a a
a a a
.
.
.
a a a ... a a a (j - i + 1個a)

共有j - i + 1個homogenous substrings