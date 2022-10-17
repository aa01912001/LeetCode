題號: 1855. Maximum Distance Between a Pair of Values
難度: Medium

## 問題描述

You are given two **non-increasing 0-indexed** integer arrays `nums1` and `nums2`.

A pair of indices `(i, j)`, where `0 <= i < nums1.length` and `0 <= j < nums2.length`, is **valid** if both `i <= j` and `nums1[i] <= nums2[j]`. The **distance** of the pair is `j - i`.

Return the **maximum distance** of any **valid** pair `(i, j)`. If there are no valid pairs, return `0`.

An array `arr` is **non-increasing** if `arr[i-1] >= arr[i]` for every `1 <= i < arr.length`.

**Example 1:**

```
Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
Output: 2
Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
The maximum distance is 2 with pair (2,4).
```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 10^5`
- `1 <= nums1[i], nums2[j] <= 10^5`
- Both `nums1` and `nums2` are **non-increasing**.


---
## 解決思路

此題我們只需要透過two pointers的方式使`p1`、`p2`分別由`nums1`、`nums2`由左至右走即可，一但我們發現目前`p1 <= p2`且`nums1[p1] <= nums2[p2]`，我們就更新解答值，並且`p2++`來尋求更佳的可能性，否則若當前為invalid，則`p1++`來進一步地嘗試。