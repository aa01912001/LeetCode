題號: 2762. Continuous Subarrays

難度: Medium

## 問題描述

You are given a **0-indexed** integer array `nums`. A subarray of `nums` is called **continuous** if:

- Let `i, i + 1, ..., j` be the indices in the subarray. Then, for each pair of indices `i <= i₁, i₂ <= j`,`0 <= |nums[i₁] - nums[i₂]| <= 2`

Return the total number of **continuous** subarrays.

A subarray is a contiguous **non-empty** sequence of elements within an array.


**Example 1:**
```
Input: nums = [5,4,2,4]
Output: 8
Explanation: 
Continuous subarray of size 1: [5], [4], [2], [4].
Continuous subarray of size 2: [5,4], [4,2], [2,4].
Continuous subarray of size 3: [4,2,4].
There are no subarrys of size 4.
Total continuous subarrays = 4 + 3 + 1 = 8.
It can be shown that there are no more continuous subarrays.
```
**Constraints:**

- `1 <= nums.length <= 10^5`
- `1 <= nums[i] <= 10^9`

**解決思路:**

我們使用 monotonic deque 來維護 window 的最大&最小值，其中:

- `max_dq`保持從大到小
- `min_dq`保持從小到大

若當前`max_dq[0] - min_dq[0] > 2`，我們就不斷縮進左邊界(`left`)，若`nums[left]`是為當前的`max_dq[0]`或`min_dq[0]`，則pop掉最前面的元素(因為左邊界縮進了)。

每回合直到`max_dq[0] - min_dq[0] <= 2`，代表當前window內的元素都滿足後，我們就將解答加上`right - left + 1`(可能的子陣列個數)。