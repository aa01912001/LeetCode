題號: 17. Letter Combinations of a Phone Number
難度: Medium

## 問題描述
Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![](https://hackmd.io/_uploads/SyoLJKUxa.png)

**Example 1:**
```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Constraints:**

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

## 解決思路
此題我們首先建立一個數字對字符的table，之後只要透過DFS的方式建構所有的可能字串即可。