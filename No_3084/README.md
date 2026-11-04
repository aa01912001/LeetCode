Problem Number: 3084. Count Substrings Starting and Ending with Given Character

Difficulty: `Medium`

## Problem Description

You are given a string `s` and a character `c`. Return the total number of **substrings** of `s` that start and end with `c`.

**Example 1:**
```
Input: s = "abada", c = "a"

Output: 6
```
**Constraints:**

- `1 <= s.length <= 10^5`
- `s` and `c` consist only of lowercase English letters.

**Intuition:**

We can simply count the frequency of c in s, store it in count, and use the mathematical formula $\binom{\text{count}}{2} + \binom{\text{count}}{1}$ to get the answer.

- $\binom{\text{count}}{2}$ represents the number of valid substrings with different start and end indices.
- $\binom{\text{count}}{1}$ represents the number of valid substrings with same start and end indices.