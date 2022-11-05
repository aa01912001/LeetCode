題號: 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
難度: Medium

## 問題描述

You are given an integer array `nums`.

In one move, you can choose one element of `nums` and change it to **any value**.

Return the minimum difference between the largest and smallest value of `nums` **after performing at most three moves**.

**Example 1:**

```
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 0.
It can be shown that there is no way to make the difference 0 in 3 moves.
```

**Constraints:**

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

---
## 解決思路

此題我們可以很明顯的看出當`nums.size()`小於等於4時，解答必為0；而當長度大於等於5時，我們可以先對`nums`做sorting，並且最優解法一定是從首尾中改掉某三個數，因此解答必為以下最小者:

`nums[n-1] - nums[3]`、`nums[n-2] - nums[2]`、`nums[n-3] - nums[1]`、`nums[n-4] - nums[0]`

原因在於我們必須要盡量緊縮整個`nums`的範圍，因此必須從當前最大或最小的數字進行排除。