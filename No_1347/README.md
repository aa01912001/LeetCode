題號: 1347. Minimum Number of Steps to Make Two Strings Anagram

難度: Medium

## 問題描述
Given two equal-size strings `s` and `t`. In one step you can choose **any character** of `t` and replace it with **another character**.

Return the minimum number of steps to make `t` an anagram of `s`.

An **Anagram** of a string is a string that contains the same characters with a different (or the same) ordering.

Example 1:
```
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
```
---
## 解決思路
先計算s中每個字元的數量(存在count array中)，再減去t中每個字元的數量。最後再將count array中的每個字元數量總和相加，<font color=#f00>但因為s與t中相異字元會重複計算到，所以要將此結果除以2後return</font>。
