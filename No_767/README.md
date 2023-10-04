題號: 767. Reorganize String
難度: Medium

## 問題描述
Given a string `s`, rearrange the characters of `s` so that any two adjacent characters are not the same.

Return any possible rearrangement of `s` or return `""` if not possible.

**Example 1:**
```
Input: s = "aab"
Output: "aba"
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of lowercase English letters.

## 解決思路
此題我們只需要透過max heap來記錄每個字元及其剩餘個數，之後我們只要每回合挑出兩個剩餘最大個數的字元依序組合成新字串即可。