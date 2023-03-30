題號: 2348. Number of Zero-Filled Subarrays
難度: Medium

## 問題描述
Given an integer array `nums`, return the number of **subarrays** filled with `0`.

A **subarray** is a contiguous non-empty sequence of elements within an array.

**Example 1:**
```
Input: nums = [1,3,0,0,2,0,0,4]
Output: 6
Explanation: 
There are 4 occurrences of [0] as a subarray.
There are 2 occurrences of [0,0] as a subarray.
There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## 解決思路
此題我們只需要利用一個變數`count`來記錄當前連續的`0`的個數即可。若當前`nums[i]`為`0`我們就將解答加上`count + 1`，代表以當前`0`為結尾的子陣列個數。否則將`count`重置為`0`。