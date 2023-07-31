題號: 795. Number of Subarrays with Bounded Maximum
難度: Medium

## 問題描述
Given an integer array `nums` and two integers `left` and `right`, return the number of contiguous non-empty **subarrays** such that the value of the maximum array element in that subarray is in the range `[left, right]`.

The test cases are generated so that the answer will fit in a **32-bit** integer.

**Example 1:**
```
Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`
- `0 <= left <= right <= 10^9`

## 解決思路
此題我們利用兩個變數`l`、`r`來記錄一個子陣列的左右邊界，使其陣列中最大值介於`[left, right]`。

若`nums[i]`大於`right`，表示之前的合法子陣列範圍已不可用，因此更新`l`、`r`為當前索引數。
若`nums[i]`大於等於`left`，表示我們可以擴展右邊界，因此更新`r`為當前索引數。

並且每回合我們將解答值加上`r - l`。

Note: `(l, r]`的範圍表示其中的所有索引位置的值皆介於`[left, right]`，因此即使若`r+1`的值小於`left`，我們也可以保證有`r - l`個合法子陣列符合題意(也就是從`(l, r]`任挑一個左邊界值，配合`r+1`為右邊界值，可形成一合法子陣列)。