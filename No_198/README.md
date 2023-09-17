題號: 198. House Robber
難度: Medium

## 問題描述
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight **without alerting the police**.

**Example 1:**
```
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Constraints:**

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 400`

## 解決思路
此題為典型的DP題。

對於`nums[0]~nums[i]`之最大值我們知道來自於下列兩種情形:

1. `nums[i]`有取得，因此`nums[i-1]`不可能取得，此情形的最大值為`nums[i]`加上`nums[0]~nums[i-2]`之解。

2. `nums[i]`不取得，因此答案來自於`nums[0]~nums[i-1]`之解。

因此我們令`dp[i]`為`nums[0]~nums[i]`之解，其狀態轉移式如下:

`dp[i] = max(dp[i-2] + nums[i], nums[i-1])`