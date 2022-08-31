題號: 238. Product of Array Except Self
難度: Medium

## 問題描述

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

**Example 1:**
```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```
**Constraints:**

- `2 <= nums.length <= 10^5`
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

---
## 解決思路

此題我們可採用**prefix sum**的思想，分別計算出每個數左右兩邊的prefix product後，針對`nums[i]`，我們只需要將其左邊的prefix product及右邊的prefix product相乘後即為該位置的答案。