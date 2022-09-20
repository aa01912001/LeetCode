題號: 1004. Max Consecutive Ones III
難度: Medium

## 問題描述

Given a binary array `nums` and an integer `k`, return the maximum number of consecutive `1`'s in the array if you can flip at most `k` `0`'s.

**Example 1:**
```
Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

---
## 解決思路

此題我們透過sliding window的方式，將window中0之個數限制在小於等於`k`即可，同時一邊將解答值與window長度進行比較更新即可。
