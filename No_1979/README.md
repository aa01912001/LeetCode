題號: 1979. Find Greatest Common Divisor of Array

難度: Easy

## 問題描述

Given an integer array `nums`, return the **greatest common divisor** of the smallest number and largest number in `nums`.

The **greatest common divisor** of two numbers is the largest positive integer that evenly divides both numbers.


**Example 1:**

```
Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.
```

**Constraints:**

- `2 <= nums.length <= 1000`
- `1 <= nums[i] <= 1000`

---
## 解決思路

此題我們只需要找出最大最小值，並用輾轉相除法得到GCD即可。


