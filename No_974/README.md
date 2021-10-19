題號: 974. Subarray Sums Divisible by K

難度: Medium

## 問題描述

Given an integer array `nums` and an integer `k`, return the number of non-empty **subarrays** that have a sum divisible by `k`.

A **subarray** is a **contiguous** part of an array.

**Example 1:**

```
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-10^4 <= nums[i] <= 10^4`
- `2 <= k <= 10^4`

---
## 解決思路

此題我們可利用prefix sum的方式搭配`unordered_map<int, int>`的方法來解。我們在計算每個索引值的prefix sum後，首先判斷是否該prefix sum可被`k`整除，若是的話則把答案加一，否則將解答加上去hash map中尋找`prefix sum % k`的個數(代表有幾段從0開始的連續子陣列，其`prefix sum % k`亦與當前prefix sum同餘，使得當前prefix sum減去這段prefix sum可被`k`整除)，最後將`prefix sum % k`餘hash map中加一即可。




