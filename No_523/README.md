題號: 523. Continuous Subarray Sum
難度: Medium

## 問題描述

Given an integer array `nums` and an integer `k`, return `true` if `nums` has a continuous subarray of size **at least two** whose elements sum up to a multiple of `k`, or `false` otherwise.

An integer `x` is a multiple of `k` if there exists an integer `n` such that `x = n * k`. `0` is **always** a multiple of `k`.

**Example 1:**
```
Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`
- `0 <= sum(nums[i]) <= 2^31 - 1`
- `1 <= k <= 2^31 - 1`

---
## 解決思路

此題我們可以利用prefix sum的思想將所有`sum(nums[0]~nums[i]) % k`(令該值為mSum)放入`unordered_map<int, int>`中，其中value為該值第一次出現的索引位置，在每回合中，若發現當前mSum值曾被記錄在map中，且兩個索引值大於1，則代表兩索引值之間的nums之和能被`k`整除，因此返回true即可。