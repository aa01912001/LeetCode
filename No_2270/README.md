題號: 2270. Number of Ways to Split Array
難度: Medium

## 問題描述

You are given a **0-indexed** integer array `nums` of length `n`.

`nums` contains a **valid split** at index `i` if the following are true:

- The sum of the first `i + 1` elements is **greater than or equal** to the sum of the last `n - i - 1` elements.
- There is **at least one** element to the right of `i`. That is, `0 <= i < n - 1`.

Return the number of **valid split**s in `nums`.

**Example 1:**
```
Input: nums = [10,4,-8,7]
Output: 2
Explanation: 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.
```
**Constraints:**

- `- 2 <= nums.length <= 10^5`
- `-10^5 <= nums[i] <= 10^5`

---
## 解決思路

此題我們首先計算所有`nums[i]`的prefis sum，與`nums`的總和(存於`sum`)後，再分別判斷對於`nums[i]`來說其prefix sum是否大於等於`sum-prefixSum[i]`，若是的話則將解答值加1即可。

Note: 最後一個元素不用判斷，因為題目規定右邊必定要有一個以上的元素存在。