題號: 896. Monotonic Array

難度: Easy

## 問題描述

An array is **monotonic** if it is either monotone increasing or monotone decreasing.

An array `nums` is monotone increasing if for all `i <= j, nums[i] <= nums[j]`. An array `nums` is monotone decreasing if for all `i <= j, nums[i] >= nums[j]`.

Given an integer array `nums`, return `true` if the given array is monotonic, or `false` otherwise.

**Example 1:**

```
Input: nums = [1,2,2,3]
Output: true
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`


---
## 解決思路

此題只需要遍歷`nums`一次，中途判斷是否為遞增或遞減即可。


