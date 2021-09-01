題號: 55. Jump Game

難度: Medium

## 問題描述

You are given an integer array `nums`. You are initially positioned at the array's **first index**, and each element in the array represents your maximum jump length at that position.

Return `true` if you can reach the last index, or `false` otherwise.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 10^5`

---
## 解決思路

此題我們只需要利用greedy的策略，從`nums[0]`開始遍歷看看是否能跳至最後一個位置。其中我們用`remain`變數來紀錄剩下能夠跳的距離，若發現當下的`num[i]`大於`remain`的話，就把`remain`更新成`num[i]`繼續往下走。
