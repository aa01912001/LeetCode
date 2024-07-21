題號: 2938. Separate Black and White Balls
難度: Medium

## 問題描述
There are `n` balls on a table, each ball has a color black or white.

You are given a **0-indexed** binary string `s` of length `n`, where `1` and `0` represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the **minimum** number of steps to group all the black balls to the right and all the white balls to the left.

**Example 1:**
```
Input: s = "101"
Output: 1
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "011".
Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.
```

**Constraints:**

- `1 <= n == s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`

## 解決思路
此題我們準備一變數`steps`, 表示需要將當前`0`移動至左邊所需的步數。
我們從左至右遍歷`s`，當遇到`0`，則將解答加上`steps`，否則更新`steps = steps + 1`。

