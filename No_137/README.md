題號: 137. Single Number II
難度: Medium

## 問題描述
Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

**Example 1:**
```
Input: nums = [2,2,3,2]
Output: 3
```

**Constraints:**

- `1 <= nums.length <= 3 * 10^4`
- `-2^31 <= nums[i] <= 2^31 - 1`
- Each element in `nums` appears exactly **three times** except for one element which appears **once**.

## 解決思路
此題我們可以分別計算所有bit位數的總和，再對3取餘後，加入解答中即可。