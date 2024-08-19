題號: 650. 2 Keys Keyboard
難度: Medium

## 問題描述
There is only one character `'A'` on the screen of a notepad. You can perform one of two operations on this notepad for each step:

- Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
- Paste: You can paste the characters which are copied last time.

Given an integer `n`, return the minimum number of operations to get the character `'A'` exactly `n` times on the screen.

**Example 1:**
```
Input: n = 3
Output: 3
Explanation: Initially, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
```

**Constraints:**

- `1 <= n <= 1000`

**解決思路:**
此題我們對於`n`來說其最多從一個A不斷複製`n-1`次。但也可以從其他小於`n`且整除`n`的數字`j`，不斷貼上`i - j / j`次來補滿`n`個A。

因此我們知道對於數字`n`來說，其DP的狀態轉移式為:

- `dp[1] = 0` 
- `dp[i] = min(dp[i], dp[j] + i / j)`

其中: `1 <= j <= i / 2` (因為大於`i / 2`的數，不可能藉由複製來補滿`j`個A)

如此我們依序迭代計算`dp[2] ~ dp[n]`，即可得到最終解答。

過程中若發現`j`無法整除`i`，則跳過從`dp[j]`計算出`dp[i]`的可能性。