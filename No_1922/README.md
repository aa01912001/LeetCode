題號: 1922. Count Good Numbers

難度: Easy

## 問題描述
A digit string is **good** if the digits (**0-indexed**) at **even** indices are **even** and the digits at **odd** indices are **prime** (`2`, `3`, `5`, or `7`).

- For example, `"2582"` is good because the digits (`2` and `8`) at even positions are even and the digits (`5` and `2`) at odd positions are prime. However, `"3245"` is not good because `3` is at an even index but is not even.

Given an integer `n`, return the **total** number of good digit strings of length `n`. Since the answer may be large, **return it modulo** `10^9 + 7`.

A **digit string** is a string consisting of digits 0 through 9 that may contain leading zeros.

**Example 1:**
```
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
```

**Constraints:**

- `1 <= n <= 10^15`

**解決思路:**

首先我們需要計算`n`的偶數位數及奇數位數個數有多少，之後分別計算其可能性數量並相乘後即為解答。

在計算的過程中由於測資的`n`非常大，我們需要使用快速冪計算方式來加快我們的程式，其基本的思想如下:

要算 a^b (mod M)，直接做 a * a * ... * a (b 次) 會超時。

快速冪的想法：

- 如果 b 是偶數：
  a^b = (a^(b/2))^2
- 如果 b 是奇數：
  a^b = a * a^(b-1)

這樣每次把指數減半，時間複雜度從 O(b) 降到 O(log b)。

