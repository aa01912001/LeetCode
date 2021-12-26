題號: 368. Largest Divisible Subset

難度: Medium

## 問題描述

Given a set of **distinct** positive integers `nums`, return the largest subset `answer` such that every pair `(answer[i], answer[j])` of elements in this subset satisfies:

- `answer[i] % answer[j] == 0`, or
- `answer[j] % answer[i] == 0`

If there are multiple solutions, return any of them.

**Example 1:**
```
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
```


**Constraints:**

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10^9`
- All the integers in `nums` are **unique**.

---
## 解決思路

此題可利用DP的策略來解。

首先我們需要對`nums`去做遞增排序，之後去維護一個`vector<vector<int>> dp`的結構，其中`dp[i]`代表包含`nums[i]`為最後一個的**Largest Divisible Subset**。

而對於`dp[i]`的更新方式來說，我們必須考慮`nums[0]~nums[i-1]`是否可以整除`nums[i]`，假設`nums[j]`能夠整除`nums[i]`，就接著考慮`dp[j]`的長度是否大於等於`d[i]`，若是的話就把`dp[i]`更新為`dp[j]`後再`push_back(nums[i])`，表示當前的`dp[i]`是包含`nums[i]`所最大的**Largest Divisible Subset**。

最後我們只要把最長的`dp[0]~dp[nums.size()]`取出即為正確答案。

**Note:** 因為我們一開始將`nums`做遞增排序，因此假設`nums[j]`能夠整除`nums[i]`的話，`dp[j]`中的數也一定能夠整除`nums[i]`。