題號: 528. Random Pick with Weight
難度: Medium

## 問題描述

You are given a **0-indexed** array of positive integers `w` where `w[i]` describes the **weight** of the `ith` index.

You need to implement the function `pickIndex()`, which **randomly** picks an index in the range `[0, w.length - 1]` (**inclusive**) and returns it. The **probability** of picking an index `i` is `w[i] / sum(w)`.

- For example, if `w = [1, 3]`, the probability of picking index `0` is `1 / (1 + 3) = 0.25` (i.e., `25%`), and the probability of picking index `1` is `3 / (1 + 3) = 0.75` (i.e., `75%`).

**Example 1:**

```
Input
["Solution","pickIndex"]
[[[1]],[]]
Output
[null,0]

Explanation
Solution solution = new Solution([1]);
solution.pickIndex(); // return 0. The only option is to return 0 since there is only one element in w.
```

**Constraints:**

- `1 <= w.length <= 10^4`
- `1 <= w[i] <= 10^5`
- `pickIndex` will be called at most `10^4` times.

---
## 解決思路

此題我們可以計算出`w`之prefix sum(存於`wSum`中)，之後於`pickIndex()`中隨機挑選一個介於`1~wSum().back()`之數(`target`)，之後我們只需要尋找此`target`是位於哪一個`wSum`範圍的index即可(相當於`w`之index)，而程式中我們使用binary search來降地搜尋的時間。

