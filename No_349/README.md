題號: 349. Intersection of Two Arrays

難度: Easy

## 問題描述

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be **unique** and you may return the result in **any order**.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Constraints:**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

---
## 解決思路

此題我們可利用`unordered_set<int>`將`nums1`中的數存入後，再去判斷`nums2`中的數有沒有在set中即可。

