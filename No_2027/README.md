題號: 2027. Minimum Moves to Convert String
難度: Easy

## 問題描述

You are given a string `s` consisting of `n` characters which are either `'X'` or `'O'`.

A **move** is defined as selecting **three consecutive characters** of `s` and converting them to `'O'`. Note that if a move is applied to the character `'O'`, it will stay the **same**.

Return the **minimum** number of moves required so that all the characters of `s` are converted to `'O'`.

```
Input: s = "XXX"
Output: 1
Explanation: XXX -> OOO
We select all the 3 characters and convert them in one move.
```

**Constraints:**

- `3 <= s.length <= 1000`
- `s[i]` is either `'X'` or `'O'`.

---
## 解決思路

此題我們只需要從頭遍歷一次`s`，只要遇到'X'，就將解答加一，並且由於一次的move會將後面兩個字元也變為'O'，因此我們需要跳過後面兩個字元的檢查。

