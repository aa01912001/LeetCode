題號: 350. Intersection of Two Arrays II

難度: Easy

## 問題描述

Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

**Example 1:**

```
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

Constraints:

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

---
## 解決思路

此題我們可以利用兩個`unordered_map<int, int>` `hmap1, hmap2`來分別記錄`nums1`與`nums2`中數字出現的頻率，之後再用`hmap1`與`hmap2`找出共同的數字即可。