題號: 813. Largest Sum of Averages
難度: Medium

## 問題描述
You are given an integer array `nums` and an integer `k`. You can partition the array into **at most** `k` non-empty adjacent subarrays. The **score** of a partition is the sum of the averages of each subarray.

Note that the partition must use every integer in `nums`, and that the score is not necessarily an integer.

Return the maximum **score** you can achieve of all the possible partitions. Answers within `10^-6` of the actual answer will be accepted.

**Example 1:**
```
Input: nums = [9,1,2,3,9], k = 3
Output: 20.00000
Explanation: 
The best choice is to partition nums into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `1 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

---
## 解決思路

此題我們只需要透過DP的方式解決即可;首先我們先定義`dp[i][j]`為將前`j`個元素分為`i`群的最大平均和。因此，我們可以定義dp的狀態轉移式如下:

`dp[i][j] = max(dp[i-1][t] + avg(nums[t+1], nums[j]), t: i-1 ~ j-1)`

為了加速計算某個區間的平均值，我們會在一開始將`nums`進行prefix sum以便後續使用。