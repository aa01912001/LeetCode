題號: 996. Number of Squareful Arrays

難度: Hard

## 問題描述

An array is **squareful** if the sum of every pair of adjacent elements is a **perfect square**.

Given an integer array `nums`, return the number of permutations of nums that are **squareful**.

Two permutations `perm1` and `perm2` are different if there is some index `i` such that `perm1[i] != perm2[i]`.

**Example 1:**

```
Input: nums = [1,17,8]
Output: 2
Explanation: [1,8,17] and [17,8,1] are the valid permutations.
```

**Constraints:**

- `1 <= nums.length <= 12`
- `0 <= nums[i] <= 10^9`

---
## 解決思路

此題我們可以利用`backtracking`的策略來遍歷所有的permutation，而在遞迴當中當我們計算到某一個索引的permutation的時候，就與前一個位置的索引值進行加總並且判斷是否為完全平方數，若是的話就繼續往下進行permutaion的遞迴，否則中止此分支的遞迴。
