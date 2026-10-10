題號: 2457. Minimum Addition to Make Integer Beautiful

難度: `Medium`

## 問題描述


You are given two positive integers `n` and `target`.

An integer is considered **beautiful** if the sum of its digits is less than or equal to `target`.

Return the *minimum* *non-negative* integer `$x$` such that `n + x` *is beautiful*. The input will be ge


**Example 1:**
```
Input: n = 16, target = 6
Output: 4
Explanation: Initially n is 16 and its digit sum is 1 + 6 = 7. After adding 4, n becomes 20 and digit sum becomes 2 + 0 = 2. It can be shown that we can not make n beautiful with adding non-negative integer less than 4.
```
**Constraints:**

- `1 <= n <= 10^12`
- `1 <= target <= 150`
- The input will be generated such that it is always possible to make `n` beautiful.

**解決思路:**

此只只需要採用greedy的方式，嘗試從最小位數的digit依序讓他變0，直到整個數字的digits總和小於等於target即可。