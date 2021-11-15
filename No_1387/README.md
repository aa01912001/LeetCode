題號: 1387. Sort Integers by The Power Value

難度: Medium

## 問題描述

The power of an integer `x` is defined as the number of steps needed to transform `x` into `1` using the following steps:

- if `x` is even then `x = x / 2`
- if `x` is odd then `x = 3 * x + 1`

For example, the power of x = 3 is 7 because 3 needs 7 steps to become 1 (3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1).

Given three integers `lo`, `hi` and `k`. The task is to sort all integers in the interval `[lo, hi]` by the power value in **ascending order**, if two or more integers have **the same** power value sort them by **ascending order**.

Return the `k-th` integer in the range `[lo, hi]` sorted by the power value.

Notice that for any integer `x` `(lo <= x <= hi)` it is **guaranteed** that `x` will transform into `1` using these steps and that the power of `x` is will **fit** in 32 bit signed integer.

**Example 1:**

```
Input: lo = 12, hi = 15, k = 2
Output: 13
Explanation: The power of 12 is 9 (12 --> 6 --> 3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1)
The power of 13 is 9
The power of 14 is 17
The power of 15 is 17
The interval sorted by the power value [12,13,14,15]. For k = 2 answer is the second element which is 13.
Notice that 12 and 13 have the same power value and we sorted them in ascending order. Same for 14 and 15.
```

**Constraints:**

- `1 <= lo <= hi <= 1000`
- `1 <= k <= hi - lo + 1`

---
## 解決思路

此題我們可利用遞迴去計算出從`lo`到`hi`的power value，而我們可利用`unordered_map<int, int> hmap;`來保存曾經算過的值來實施**dynamic programming**，另外我們使用`min heap`來儲存`pair<int, int>`，first為某數i的power value，而second為i，如此之後我們只要實施pop操作`k`次後，其最後pop出的pair之second即為最終解答。 









