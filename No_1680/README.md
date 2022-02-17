題號: 1680. Concatenation of Consecutive Binary Numbers
難度: Medium

## 問題描述

Given an integer `n`, return the **decimal value** of the binary string formed by concatenating the binary representations of `1` to `n` in order, **modulo** `10^9 + 7`.

**Example 1:**
```
Input: n = 12
Output: 505379714
Explanation: The concatenation results in "1101110010111011110001001101010111100".
The decimal value of that is 118505380540.
After modulo 109 + 7, the result is 505379714.
```


**Constraints:**

- `1 <= n <= 10^5`

---
## 解決思路

此題我們只要從1至n依序加總，其中，每個數在相加之前先將當前加總左移當前此數之二進位表示法之長度即可。

