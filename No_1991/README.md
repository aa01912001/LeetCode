題號: 1991. Find the Middle Index in Array
難度: Easy

## 問題描述

Given a **0-indexed** integer array `nums`, find the **leftmost** `middleIndex` (i.e., the smallest amongst all the possible ones).

A `middleIndex` is an index where `nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1]`.

If `middleIndex == 0`, the left side sum is considered to be `0`. Similarly, if `middleIndex == nums.length - 1`, the right side sum is considered to be 0.

Return the **leftmost** `middleIndex` that satisfies the condition, or `-1` if there is no such index.

**Example 1:**
```
Input: nums = [2,3,-1,8,4]
Output: 3
Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
The sum of the numbers after index 3 is: 4 = 4
```

**Constraints:**

- `1 <= nums.length <= 100`
- `-1000 <= nums[i] <= 1000`

---
## 解決思路

此題我們只需要將每個位置的left sum與right sum計算出來後，在從`nums`最左邊開始比較其left sum與right sum是否相等即可。

