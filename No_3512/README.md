題號: 3512. Minimum Operations to Make Array Sum Divisible by K

難度: Easy

## 問題描述

You are given an integer array `nums` and an integer `k`. You can perform the following operation any number of times:

- Select an index `i` and replace `nums[i]` with `nums[i] - 1`.

Return the **minimum** number of operations required to make the sum of the array divisible by `k`.


**Example 1:**
```
Input: nums = [3,9,7], k = 5
Output: 4
Explanation:

- Perform 4 operations on nums[1] = 9. Now, nums = [3, 5, 7].
- The sum is 15, which is divisible by 5.


```
**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`
- `1 <= k <= 100`

**解決思路:**

直接將`nums`所有元素加總並取`k`的餘數即為我們應該透過運算消去的次數。
