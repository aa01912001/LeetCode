題號: 1296. Divide Array in Sets of K Consecutive Numbers
難度: Medium

## 問題描述

Given an array of integers `nums` and a positive integer `k`, check whether it is possible to divide this array into sets of `k` consecutive numbers.

Return `true` if it is possible. Otherwise, return `false`.

**Example 1:**
```
Input: nums = [1,2,3,3,4,4,5,6], k = 4
Output: true
Explanation: Array can be divided into [1,2,3,4] and [3,4,5,6].
```

**Constraints:**

- `1 <= k <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

---
## 解決思路

此題我們可使用`map<int, int>`來儲存每個數有多少個，之後每次再由小到大取出`k`個來判斷是否皆相差1，直到map為空後再返回true。

