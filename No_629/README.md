題號: 629. K Inverse Pairs Array
難度: Hard

## 問題描述
For an integer array `nums`, an **inverse pair** is a pair of integers `[i, j]` where `0 <= i < j < nums.length` and `nums[i] > nums[j]`.

Given two integers n and k, return the number of different arrays consist of numbers from `1` to `n` such that there are exactly `k` **inverse pairs**. Since the answer can be huge, return it **modulo** `10^9 + 7`.

**Example 1:**
```
Input: n = 3, k = 0
Output: 1
Explanation: Only the array [1,2,3] which consists of numbers from 1 to 3 has exactly 0 inverse pairs.
```
**Constraints:**

- `1 <= n <= 1000`
- `0 <= k <= 1000`

## 解決思路
此題我們可以利用DP的方式求解。首先我們假設`nums`元素為`x_1 x_2 x_3 ... x_n-2 x_n-1 x_n`，我們不考慮x_1 ~ x_n-1的順序，只知道x_n為元素中最大值(也就是`n`)，因此我們可以觀察到如下規律:

- 若將x_n放至最後，則無任一元素可以與x_n形成inverse pair，需要另外k個inverse pair

- 若將x_n放至x_n-1之前，只有一元素(x_n-1)可以與x_n形成inverse pair，需要另外k-1個inverse pair

- 若將x_n放至x_n-2之前，只有兩元素(x_n-1、x_n-2)可以與x_n形成inverse pair，需要另外k-2個inverse pair

- 以下如上規律同樣推斷，若將x_n插入中間，會與其後續的所有元素形成inverse pair，而不會影響其之前的所有元素

因此我們可以輕易地將DP的狀態轉移式寫出:

`dp[n][k] = dp[n-1][k] + dp[n-1][k-1] + dp[n-1][k-2] + ... + dp[n-1][k-min(k, n-1)]`

而程式中我們需要在每一回合(假設為第`n`回合)計算利用前一回合(`n-1`)的prefix sum來加速DP的計算以避免OJ timeout。
