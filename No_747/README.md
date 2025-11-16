題號: 747. Largest Number At Least Twice of Others

難度: Easy

## 問題描述

You are given an integer array `nums` where the largest integer is **unique**.

Determine whether the largest element in the array is **at least twice** as much as every other number in the array. If it is, return the **index** of the largest element, or return `-1 `otherwise.


**Example 1:**
```
Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
```
**Constraints:**

- `2 <= nums.length <= 50`
- `0 <= nums[i] <= 100`
- The largest element in `nums` is unique.

**解決思路:**

找出最大及次大的數比較即可。