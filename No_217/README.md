題號: 217. Contains Duplicate
難度: Easy

## 問題描述

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

**Example 1:**
```
Input: nums = [1,2,3,1]
Output: true
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---
## 解決思路

此題只需要利用`unordered_set<int>`來儲存每個數，並在之後判斷當前數是否已經存在其中即可。