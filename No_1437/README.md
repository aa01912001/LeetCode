題號: 1437. Check If All 1's Are at Least Length K Places Away

難度: Easy

## 問題描述

Given an array `nums` of 0s and 1s and an integer `k`, return `True` if all 1's are at least `k` places away from each other, otherwise return `False`.

Example 1:

![image alt](https://assets.leetcode.com/uploads/2020/04/15/sample_1_1791.png)

```
Input: nums = [1,0,0,0,1,0,0,1], k = 2
Output: true
Explanation: Each of the 1s are at least 2 places away from each other.
```

Constraints:

- `1 <= nums.length <= 10^5`
- `0 <= k <= nums.length`
- `nums[i]` is `0` or `1`

---
## 解決思路

此題只需要遍歷`nums`一次，過程中一旦發現1，就去比較距離上一個1是否有`k`的距離即可。