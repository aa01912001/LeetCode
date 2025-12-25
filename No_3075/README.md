題號: 3075. Maximize Happiness of Selected Children


難度: `Medium`

## 問題描述

You are given an array `happiness` of length `n`, and a **positive** integer `k`.

There are `n` children standing in a queue, where the `i`-th child has happiness value `happiness[i]`. You want to select `k` children from these `n` children in `k` turns.

In each turn, when you select a child, the happiness value of **all the children that have not been selected till now** decreases by `1`.  
Note that the happiness value **cannot become negative** and gets decremented **only if it is positive**.

Return the **maximum sum of the happiness values** of the selected children you can achieve by selecting `k` children.


**Example 1:**
```
Input: happiness = [1,2,3], k = 2
Output: 4
Explanation: We can pick 2 children in the following way:
- Pick the child with the happiness value == 3. The happiness value of the remaining children becomes [0,1].
- Pick the child with the happiness value == 1. The happiness value of the remaining child becomes [0]. Note that the happiness value cannot become less than 0.
The sum of the happiness values of the selected children is 3 + 1 = 4.
```
**Constraints:**

- `1 <= n == happiness.length <= 2 * 10^5`
- `1 <= happiness[i] <= 10^8`
- `1 <= k <= n`

**解決思路:**

此題就是先做遞減排序`happiness`，依序挑選較大的小孩，同時要扣掉漸增的損失即可。

若已經挑完`k`個小孩，或是當前小孩的快樂度已經為0的話，就不需要再繼續往下挑選了。