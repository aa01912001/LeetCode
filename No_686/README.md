Problem Number: 686. Repeated String Match

Difficulty: `Medium`

## Problem Description

You are given two strings `a` and `b` consisting of lowercase English letters.

Return the **minimum** number of times you should repeat string `a` so that string `b` is a **substring** of it. If it is **impossible** for `b` to be a substring of `a` after repeating it, return -1.

**Note:** string `"abc"` repeated 0 times is `""`, repeated 1 time is `"abc"` and repeated 2 times is `"abcabc"`.

A **subarray** is a contiguous sequence of elements within an array.

**Example 1:**
```
Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
```
**Constraints:**

- `1 <= a.length, b.length <= 10^4`
- `a` and `b` consist of lowercase English letters.

## Solution Intuition

We need to find the **minimum number of repetitions** required to make the length of `a` **greater than or equal to** `b` using the formula:

`min_repeats = ceil(len(b) / len(a))`

1. **Base Check**: If `b` is already a substring of `a * min_repeats`, the answer is `min_repeats`.
2. **Boundary Offset Check (+1)**: Otherwise, we check if adding one more repetition (`a * min_repeats + a`) satisfies `b`.

Why check `min_repeats + 1`?

* **Length vs. Alignment**: `min_repeats` only guarantees that the total length is sufficient (`len(a * min_repeats) >= len(b)`), not that the characters align properly.
* **Boundary Crossing**: `b` might start somewhere in the middle of the first `a` rather than index `0`, causing its tail to spill over into the next repetition. Adding one extra `a` covers all possible boundary offsets; any repetitions beyond `min_repeats + 1` will never produce new substring combinations.