題號: 1963. Minimum Number of Swaps to Make the String Balanced
難度: Medium

## 問題描述

You are given a **0-indexed** string `s` of **even** length `n`. The string consists of **exactly** `n / 2` opening brackets `'['` and `n / 2` closing brackets `']'`.

A string is called **balanced** if and only if:

- It is the empty string, or
- It can be written as `AB`, where both `A` and `B` are **balanced** strings, or
- It can be written as `[C]`, where `C` is a **balanced** string.

You may swap the brackets at any **two** indices **any** number of times.

Return the **minimum** number of swaps to make `s` **balanced**.

**Example 1:**
```
Input: s = "]]][[["
Output: 2
Explanation: You can do the following to make the string balanced:
- Swap index 0 with index 4. s = "[]][][".
- Swap index 1 with index 5. s = "[[][]]".
The resulting string is "[[][]]".
```

**Constraints:**

- `n == s.length`
- `2 <= n <= 10^6`
- `n` is even.
- `s[i]` is either `'['` or `']'`.
- The number of opening brackets `'['` equals `n / 2`, and the number of closing brackets `']'` equals `n / 2`.

---
## 解決思路

此題我們可以透過stack來找出最後所有無法配對的字元(假設個數為`n`)，因此我們可得知不合法的pair數量為`n/2`，又因為我們一次的swap可以使兩個pair成為合法pair，因此最少的swap個數即為`ceil(n/2/2)`。