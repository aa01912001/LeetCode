Problem Number: 2124. Check if All A's Appears Before All B's

Difficulty: `Easy`

## Problem Description

Given a string `s` consisting of **only** the characters `'a'` and `'b'`, return `true` *if **every** `'a'` appears before **every** `'b'` in the string*. Otherwise, return `false`.

**Example 1:**
```
Input: s = "aaabbb"
Output: true
Explanation:
The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
Hence, every 'a' appears before every 'b' and we return true.
```
**Constraints:**

* $1 \le \text{s.length} \le 100$
* `s[i]` is either `'a'` or `'b'`.

## Solution Intuition

Since `s` consists only of `'a'` and `'b'`, every `'a'` appears before every `'b'` if and only if `'ba'` does not appear in `s`. We can simply return `"ba" not in s`.