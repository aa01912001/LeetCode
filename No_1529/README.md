題號: 1529. Minimum Suffix Flips
難度: Medium

## 問題描述

You are given a **0-indexed** binary string `target` of length `n`. You have another binary string `s` of length `n` that is initially set to all zeros. You want to make `s` equal to `target`.

In one operation, you can pick an index `i` where `0 <= i < n` and flip all bits in the **inclusive** range `[i, n - 1]`. Flip means changing `'0'` to `'1'` and `'1'` to `'0'`.

Return the minimum number of operations needed to make s equal to `target`.

**Example 1:**
```
Input: target = "10111"
Output: 3
Explanation: Initially, s = "00000".
Choose index i = 2: "00000" -> "00111"
Choose index i = 0: "00111" -> "11000"
Choose index i = 1: "11000" -> "10111"
We need at least 3 flip operations to form target.
```

**Constraints:**

- `n == target.length`
- `1 <= n <= 10^5`
- `target[i]` is either `'0'` or `'1'`.

---
## 解決思路

此題相當於使用最少的operation次數將`target`翻轉成0，假設`target`如下：

`target = "0110010111"`

我們每次需要針對字串後面連續相同的字元做翻轉，從上例來看即為：

`"0110010111" -> "0110010000"` ，此時將解答次數加1，再繼續尋找相同連續字元做翻轉。

`"0110010000" -> "0110011111"`

`"0110011111" -> "0110000000"`

`"0110000000" -> "0111111111"`

`"0111111111" -> "0000000000"`

如此即可使用最少次數的operation完成目標。

由於每次operation是將`[i, n - 1]`做翻轉，因此上述的想法是用greedy之策略每次找出一個index將`target`後面儘可能多的相同部分來做翻轉，以避免不必要的翻轉次數。 
