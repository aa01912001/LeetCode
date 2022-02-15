題號: 1262. Greatest Sum Divisible by Three
難度: Medium

## 問題描述

Given an array `nums` of integers, we need to find the maximum possible sum of elements of the array such that it is divisible by three.

**Example 1:**
```
Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
```


**Constraints:**

- `1 <= nums.length <= 4 * 10^4`
- `1 <= nums[i] <= 10^4`

---
## 解決思路

此題我們可以採用DP的方法來解決想法如下：

其中我們以`sum0、sum1、sum2`來儲存當前餘數為0、1、2的可能最大值。

在遍歷`nums`個過程中，我們都先判斷`nums[i]%3`為多少，之後就更新最大`sum0、sum1、sum2`的最大值，舉例來說，`nums[i] == 1`，那麼更新`sum0`時就必須考量`max(sum0, sum2+nums[i])`，其餘情況以此類推。

最後我們只要返回`sum0`即為最終答案。

