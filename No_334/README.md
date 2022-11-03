題號: 334. Increasing Triplet Subsequence
難度: Medium

## 問題描述

Given an integer array `nums`, return `true` if there exists a triple of indices `(i, j, k)` such that `i < j < k` and `nums[i] < nums[j] < nums[k]`. If no such indices exists, return `false`.

**Example 1:**

```
Input: nums = [2,1,5,0,4,6]
Output: true
Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
```

**Constraints:**

- `1 <= nums.length <= 5 * 10^5`
- `-2^31 <= nums[i] <= 2^31 - 1`

**Follow up:** Could you implement a solution that runs in `O(n)` time complexity and `O(1)` space complexity?

---
## 解決思路

此題我們可從頭開始遍歷`nums`，並維護一邊更新兩個變數:

- `minVal`: 紀錄`nums[0]~nums[i]`，中最小的數字。

- `minValForMid`: 紀錄那些曾經大於`minVal`的數字中最小者。

假設當前遍歷數為`nums[i]`，我們判斷其是否大於`minVal`，若大於則再判斷是否大於`minValForMid`，若也大於則代表`nums[i]`為三者(`minVal`、`minValForMid`、`nums[i]`)中第三大的數，因此返回true，否則更新`minValForMid`為`nums[i]`；若`nums[i] < minVal`，則更新`minVal`為`nums[i]`。