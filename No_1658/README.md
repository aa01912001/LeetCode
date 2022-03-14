題號: 1658. Minimum Operations to Reduce X to Zero
難度: Medium

## 問題描述

You are given an integer array `nums` and an integer `x`. In one operation, you can either remove the leftmost or the rightmost element from the array `nums` and subtract its value from `x`. Note that this **modifies** the array for future operations.

Return the **minimum number** of operations to reduce `x` to **exactly** `0` if it is possible, otherwise, return `-1`.

**Example 1:**
```
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^4`
- `1 <= x <= 10^9`

---
## 解決思路

此題我們可以先由左至右將prefix sum與對應的索引位置紀錄在`unordered_map<int, int>`中，之後我們由右至左開始依序將`x`減去`nums[i]`，並同時檢視`x`的剩餘值是否存在於map中，若存在，則代表右側`n-i`個元素(`n`為`nums`之長度)加上map中所記錄prefix sum的那些左側元素可以使`x`變為0，因此我們就可以相應地更新返回值之個數。