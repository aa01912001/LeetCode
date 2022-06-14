題號: 1962. Remove Stones to Minimize the Total
難度: Medium

## 問題描述

You are given a **0-indexed** integer array `piles`, where `piles[i]` represents the number of stones in the `ith` pile, and an integer `k`. You should apply the following operation **exactly** `k` times:

- Choose any `piles[i]` and **remove** `floor(piles[i] / 2)` stones from it.

**Notice** that you can apply the operation on the **same** pile more than once.

Return the **minimum** possible total number of stones remaining after applying the k operations.

`floor(x)` is the **greatest** integer that is **smaller** than or **equal** to `x` (i.e., rounds `x` down).

**Example 1:**
```
Input: piles = [5,4,9], k = 2
Output: 12
Explanation: Steps of a possible scenario are:
- Apply the operation on pile 2. The resulting piles are [5,4,5].
- Apply the operation on pile 0. The resulting piles are [3,4,5].
The total number of stones in [3,4,5] is 12.
```
**Constraints:**

- `1 <= piles.length <= 10^5`
- `1 <= piles[i] <= 10^4`
- `1 <= k <= 10^5`

---
## 解決思路

此題我們只需要利用max heap來儲存每個pile後，之後每次挑出最大的pile進行運算並存回heap即可。

最後經過`k`次的挑選後，將heap中所有的數字加總起來即可。
