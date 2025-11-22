題號: 3190. Find Minimum Operations to Make All Elements Divisible by Three

難度: Easy

## 問題描述

You are given an integer array `nums`. In one operation, you can add or subtract 1 from **any** element of `nums`.

Return the **minimum** number of operations to make all elements of `nums` divisible by 3.


**Example 1:**
```
Input: nums = [1,2,3,4]
Output: 3
Explanation:

All array elements can be made divisible by 3 using 3 operations:

    Subtract 1 from 1.
    Add 1 to 2.
    Subtract 1 from 4.
```
**Constraints:**

- `1 <= nums.length <= 50`
- `1 <= nums[i] <= 50`

**解決思路:**

一個數mod 3有下列三個結果:

1. 等於0: 我們不需要調整此數
2. 等於1: 只需要將此數減1即可滿足
3. 等於2: 只需要將此數加1即可滿足

歸納後我們發現只需要找出數列中mod 3不等於0的元素個數即可。
