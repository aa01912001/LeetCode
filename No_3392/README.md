題號: 3392. Count Subarrays of Length Three With a Condition

難度: Easy

## 問題描述
Given an integer array `nums`, return the number of **subarrays** of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

**Example 1:**
```
Input: nums = [1,2,1,4,1]

Output: 1

Explanation:

Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
```

**Constraints:**

- `3 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

**解決思路:**

單純遍歷判斷即可
