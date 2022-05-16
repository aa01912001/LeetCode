題號: 779. K-th Symbol in Grammar
難度: Medium

## 問題描述

We build a table of `n` rows (**1-indexed**). We start by writing `0` in the `1st` row. Now in every subsequent row, we look at the previous row and replace each occurrence of `0` with `01`, and each occurrence of `1` with `10`.

- For example, for `n = 3`, the `1st` row is `0`, the `2nd` row is `01`, and the `3rd` row is `0110`.

Given two integer `n` and `k`, return the `kth` (**1-indexed**) symbol in the `nth` row of a table of `n` rows.

**Example 1:**
```
Input: n = 2, k = 2
Output: 1
Explanation: 
row 1: 0
row 2: 01
```
**Constraints:**

- `1 <= n <= 30`
- `1 <= k <= 2^n - 1`

---
## 解決思路

首先透過觀查`n = 1~4`如一下：
`n == 1： 0`
`n == 2： 01`
`n == 3： 0110`
`n == 4： 01101001`
我們可以發現當`n == i`時會等於`n == i-1`時，於尾端加上其互補的形式，因此我們可以採用遞迴的策略如下：

kthGrammar(n-1, k), if k 小於等於第n row的一半(代表只需要刪除後面一半)
!kthGrammar(n-1, k-count/2), if k 大於第n row的一半(因為後面一半與前面一半互補，因此需要加上not)

如此遞迴下去即可得到最終的正確值。