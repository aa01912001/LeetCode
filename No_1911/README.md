題號: 1911. Maximum Alternating Subsequence Sum
難度: Medium

## 問題描述

The **alternating sum** of a **0-indexed** array is defined as the **sum** of the elements at **even** indices **minus** the **sum** of the elements at **odd** indices.

- For example, the alternating sum of `[4,2,5,3]` is `(4 + 5) - (2 + 3) = 4`.

Given an array `nums`, return the **maximum alternating sum** of any subsequence of `nums` (after **reindexing** the elements of the subsequence).

A **subsequence** of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, `[2,7,4]` is a subsequence of `[4,2,3,7,2,1,4]` (the underlined elements), while `[2,4,2]` is not.

**Example 1:**
```
Input: nums = [6,2,1,2,4,5]
Output: 10
Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`


---
## 解決思路

此題相當於去尋找`nums`中之peak與valley，其中每個peak相當於subsequence中的偶數位置，而valley則為奇數位置，任一peak與其前一個valley相減即可對**Alternating Subsequence Sum**有最大的效益，因此將所有`nums`中的peak加總並扣除所有valley值即為最終答案。