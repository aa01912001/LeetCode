題號: 1749. Maximum Absolute Sum of Any Subarray

難度: Medium

## 問題描述

You are given an integer array `nums`. The **absolute sum** of a subarray `[numsl, numsl+1, ..., numsr-1, numsr]` is `abs(numsl + numsl+1 + ... + numsr-1 + numsr)`.

Return the **maximum** absolute sum of any **(possibly empty)** subarray of `nums`.

Note that `abs(x)` is defined as follows:

- If `x` is a negative integer, then `abs(x) = -x`.
- If `x` is a non-negative integer, then `abs(x) = x`.

**Example 1:**

```
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---
## 解決思路

此題可利用**Kadane's algorithm**來求出最大子陣列和與最小子陣列和後，在回傳兩個取絕對值最大的那個即可。

