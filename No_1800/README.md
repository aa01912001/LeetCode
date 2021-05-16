題號: 1800. Maximum Ascending Subarray Sum

難度: Easy

## 問題描述

Given an array of positive integers `nums`, return the maximum possible sum of an **ascending** subarray in `nums`.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray `[numsl, numsl+1, ..., numsr-1, numsr]` is **ascending** if for all `i` where `l <= i < r, numsi < numsi+1`. Note that a subarray of size `1` is **ascending**.

Example 1:

```
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
```

Constraints:

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 100`



---
## 解決思路

此題只需要遍歷`nums`一次，途中把所有**ascending subarray**的sum找出來即可。

