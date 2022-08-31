題號: 53. Maximum Subarray
難度: Medium

## 問題描述

Given an integer array `nums`, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A **subarray** is a **contiguous** part of an array.

**Example 1:**
```
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---
## 解決思路

此題我們準備一個`preSum`初始為`nums[0]`，之後每回合將`preSum`更新為`max(preSum+nums[i], nums[i])`，代表若`nums[i]`單獨一數就比`preSum+nums[i]`大的話，就不需要前面的數字包含在裡面，而我們也將新的`preSum`值與當前解答值比較進行更新。