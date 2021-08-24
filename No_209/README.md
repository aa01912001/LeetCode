題號: 209. Minimum Size Subarray Sum

難度: Medium

## 問題描述

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a **contiguous subarray** `[numsl, numsl+1, ..., numsr-1, numsr]` of which the sum is greater than or equal to `target`. If there is no such subarray, return `0` instead.

**Example 1:**

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**Constraints:**

- `1 <= target <= 10^9`
- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^5`

---
## 解決思路

此題可利用`two pointer`的方式使用`left`、`right`作為subarray的尾跟頭，其中當我們發現subarray的和大於等於`target`時就把`left`向前移縮短subaaray看看是否有更短的解，而如果發現subarray的和小於`target`時就把`right`向前移增長subaaray來補足不夠的數量。如此反覆操作到`right`超出陣列範圍後即可找出此題的解。

