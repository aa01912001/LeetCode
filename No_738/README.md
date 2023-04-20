題號: 738. Monotone Increasing Digits
難度: Medium

## 問題描述
An integer has **monotone increasing digits** if and only if each pair of adjacent digits `x` and `y` satisfy `x <= y`.

Given an integer `n`, return the largest number that is less than or equal to `n` with `monotone increasing digits`.

**Example 1:**
```
Input: n = 332
Output: 299
```

**Constraints:**

- `0 <= n <= 10^9`

## 解決思路
此題透過觀察，可以發現，若第`i`位的digit小於等於第`i+1`位的digit，則我們可沿用原本第`i`位的digit，反之，需要將包含第`i`位以後的數更新為`digit_i * base - 1`。

例如: 
32 -> 29
526 -> 499