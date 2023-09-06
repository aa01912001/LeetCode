題號: 242. Valid Anagram
難度: Easy

## 問題描述
Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and `false` otherwise.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
```
Input: s = "anagram", t = "nagaram"
Output: true
```
**Constraints:**

- `1 <= s.length, t.length <= 5 * 10^4`
- `s` and `t` consist of lowercase English letters.

`Follow up:` What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

## 解決思路
此題我們首先將`s`、`t`做sorting之後，直接比較是否相等即可。
