題號: 2787. Ways to Express an Integer as Sum of Powers

難度: Medium

## 問題描述
Given two **positive** integers `n` and `x`.

Return the number of ways `n` can be expressed as the sum of the `xth` power of **unique** positive integers, in other words, the number of sets of unique integers `[n1, n2, ..., nk]` where `n = n1^x + n2^x + ... + nk^x`.

Since the result can be very large, return it modulo `10^9 + 7`.

For example, if `n = 160` and `x = 3`, one way to express `n` is `n = 2^3 + 3^3 + 5^3`.

**Example 1:**
```
Input: n = 10, x = 2
Output: 1
Explanation: We can express n as the following: n = 3^2 + 1^2 = 10.
It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
```

**Constraints:**

- `1 <= n <= 300`
- `1 <= x <= 5`

**解決思路:**

此題我們可以先將所有小於等於`n`的`x`次方的整數放入至`powers`中，之後這個問題就相當於0/1背包問題了。其中`powers`為每個item的重量，而`n`即為背包負重限制。