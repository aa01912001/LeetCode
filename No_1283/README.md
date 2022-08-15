題號: 1283. Find the Smallest Divisor Given a Threshold
難度: Medium

## 問題描述

Given an array of integers `nums` and an integer `threshold`, we will choose a positive integer `divisor`, divide all the array by it, and sum the division's result. Find the **smallest** `divisor` such that the result mentioned above is less than or equal to `threshold`.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: `7/3 = 3` and `10/2 = 5`).

The test cases are generated so that there will be an answer.

**Example 1:**
```
Input: nums = [1,2,5,9], threshold = 6
Output: 5
Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
```
**Constraints:**

- `1 <= nums.length <= 5 * 10^4`
- `1 <= nums[i] <= 10^6`
- `nums.length <= threshold <= 10^6`

---
## 解決思路

此題我們透過**binary search**的方式從1(`low`)~INT_MAX(`high`)中去猜測我們的答案，一但我們發現mid所產生的result小於等於`threshold`，代表我們可以嘗試更小的數字，因此將`high = mid - 1`，否則，代表我們的數字太小導致超過了`threshold`，因此將`low = mid + 1`，如此，最終即可找到最小的合法數字。