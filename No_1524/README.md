題號: 1524. Number of Sub-arrays With Odd Sum

難度: Medium

## 問題描述

Given an array of integers `arr`, return the number of subarrays with an **odd** sum.

Since the answer can be very large, return it modulo `10^9 + 7`.

**Example 1:**
```
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
```


**Constraints:**

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 100`

---
## 解決思路

此題可利用DP的策略來解。

程式中，我們使用維護一個`vector<vector<int>> dp(n, vector<int>(2))`結構，其中:

- `dp[i][0]`: 代表`arr[i]`為最後且`sum`為偶數的子陣列個數
- `dp[i][1]`: 代表`arr[i]`為最後且`sum`為奇數的子陣列個數

狀態轉移公式如下:

若`arr[i]`為偶數:
- 偶 + 偶 = 偶，因此`dp[i][0] += dp[i-1][0] + 1`
- 偶 + 奇 = 奇，因此`dp[i][1] += dp[i-1][1]`

若`arr[i]`為奇數:
- 奇 + 奇 = 偶，因此`dp[i][0] += dp[i-1][1]`
- 奇 + 偶 = 奇，因此`dp[i][1] += dp[i-1][0] + 1`

最後只要把所有的`dp[i][1]`相加起來後即為解答。
