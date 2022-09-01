題號: 152. Maximum Product Subarray
難度: Medium

## 問題描述

Given an integer array `nums`, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a **32-bit** integer.

A **subarray** is a contiguous subsequence of the array.

**Example 1:**
```
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
```
**Constraints:**

- `1 <= nums.length <= 2 * 10^4`
- `-10 <= nums[i] <= 10`
- The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

---
## 解決思路

此題我們需要紀錄當前最大值與當前最小值，若遇到負數相乘會導致我們的當前最大值與當前最小值交換，因此需要額外紀錄當前最小值，而每回合更新完當前最大最小值後，我們只需要將當前最大值與解答進行比較即可。