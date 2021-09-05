題號: 930. Binary Subarrays With Sum

難度: Medium

## 問題描述

Given a binary array `nums` and an integer `goal`, return the number of non-empty **subarrays** with a sum `goal`.

A **subarray** is a contiguous part of the array.

**Example 1:**

```
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `nums[i]` is either `0` or `1`.
- `0 <= goal <= nums.length`

---
## 解決思路

此題我們可利用prefix sum與配合`unordered_map<int, int>`來解。從`nums`前面開始計算prefix sum並同時記錄此prefix sum出現的頻率，之後每遍歷一個位置我們就可以透過**當前prefix sum減去goal**後在map裡的頻率得到包含當前`nums[i]`且和為`goal`的子陣列個數。