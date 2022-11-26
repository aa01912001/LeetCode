題號: 410. Split Array Largest Sum
難度: Hard

## 問題描述

Given an integer array `nums` and an integer `k`, split `nums` into `k` non-empty subarrays such that the largest sum of any subarray is **minimized**.

Return the minimized largest sum of the split.

A **subarray** is a contiguous part of the array.

**Example 1:**
```
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `0 <= nums[i] <= 10^6`
- `1 <= k <= min(50, nums.length)`

---
## 解決思路

此題我們可以使用binary search的方式來找尋最佳的**minimized largest sum**，針對每一次的猜測mid值，我們需要判斷其是否可以在將陣列分割為`k`個情況下，使得每一個子陣列和皆小於等於mid。若合法，則將`high = mid`往下尋找更小的可能解，否則，將`low = mid + 1`向上找尋合法的目標。

對於每一次mid值是否為合法的判斷，我們可以採用greedy的方式將`nums[i]`的值從index 0依序加起來，直到當前和大於`mid`，我們則將`k`值減一，表示找到一合法的子陣列，並將當前累加數歸零後繼續尋找合法子陣列。最後判斷若`k`值大於等於0，代表當前mid值為合法(因為可以在分割`k`個子陣列的情況下使得每個子陣列之和小於等於mid)。