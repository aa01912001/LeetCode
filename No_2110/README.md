題號: 2110. Number of Smooth Descent Periods of a Stock
難度: Medium

## 問題描述

You are given an integer array `prices` representing the daily price history of a stock, where `prices[i]` is the stock price on the `ith` day.

A **smooth descent period** of a stock consists of **one or more contiguous** days such that the price on each day is **lower** than the price on the **preceding day** by **exactly** `1`. The first day of the period is exempted from this rule.

Return the number of **smooth descent periods**.

**Example 1:**
```
Input: prices = [3,2,1,4]
Output: 7
Explanation: There are 7 smooth descent periods:
[3], [2], [1], [4], [3,2], [2,1], and [3,2,1]
Note that a period with one day is a smooth descent period by the definition.
```


**Constraints:**

- `1 <= prices.length <= 10^5`
- `1 <= prices[i] <= 10^5`

---
## 解決思路

此題我們可以採用DP的方法來解決，程式中我們維護一個結構如下：

`vector<long long> dp(prices.size());`

其中，`dp[i]`代表第`i`天為最後一天的可能**smooth descent periods**數。

對於第`i`天來說，我們需要判斷其股價是否為第`i-1`天的股價-1，若是的話，代表他的**smooth descent periods**數為`dp[i-1]+1`，否則為`1`(只有自己)。

最後只要將所有dp中的數加總起來即為答案。

