Problem Number: 2396. Strictly Palindromic Number

Difficulty: `Medium`

## Problem Description

An integer `n` is **strictly palindromic** if, for **every** base `b` between `2` and `n - 2` (**inclusive**), the string representation of the integer `n` in base `b` is **palindromic**.

Given an integer `n`, return `true` if `n` *is **strictly palindromic*** and `false` *otherwise*.

A string is **palindromic** if it reads the same forward and backward.


**Example 1:**
```
Input: n = 9
Output: false
Explanation: In base 2: 9 = 1001 (base 2), which is palindromic.
In base 3: 9 = 100 (base 3), which is not palindromic.
Therefore, 9 is not strictly palindromic so we return false.
Note that in bases 4, 5, 6, and 7, n = 9 is also not palindromic.
```
**Constraints:**

- `4 <= n <= 10^5`

**Intuition:**

Since $n = 1 \cdot (n - 2)^1 + 2 \cdot (n - 2)^0$, the string representation of the integer `n` in base `n - 2` is always `"12"`, which is **not palindromic**.

Therefore, no integer `n` $(\ge 4)$ can be strictly palindromic, and the answer is always `false`.