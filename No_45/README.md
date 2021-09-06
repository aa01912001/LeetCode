題號: 45. Jump Game II

難度: Medium

## 問題描述

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Constraints:**

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`

---
## 解決思路

此題我們可利用DP的策略來解。其中`dp[i]`代表著走到`nums[i]`所需要的最小jump數量，每走到一個index(假設為j)，我們就向後看`nums[j]`個格數(因為後面`nums[j]`，可有能是來自於索引j這格)，並對每一格賦予其`min(dp[k], dp[i]+1)`，其中`k`為當格索引值。如此遍歷下去，我們就能得到每一格所需的最小jump數。