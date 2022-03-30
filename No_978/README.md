題號: 978. Longest Turbulent Subarray
難度: Medium

## 問題描述

Given an integer array `arr`, return the length of a maximum size turbulent subarray of `arr`.

A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray `[arr[i], arr[i + 1], ..., arr[j]]` of `arr` is said to be turbulent if and only if:

- For `i <= k < j`:
    - `arr[k] > arr[k + 1]` when `k` is odd, and
    - `arr[k] < arr[k + 1]` when `k` is even.

- Or, for `i <= k < j`:
    - `arr[k] > arr[k + 1]` when `k` is even, and
    - `arr[k] < arr[k + 1]` when `k` is odd.

**Example 1:**
```
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
```

**Constraints:**

- `1 <= arr.length <= 4 * 10^4`
- `0 <= arr[i] <= 10^9`



---
## 解決思路

此題我們可以準備一個DP陣列(`vector<vector<int>> dp(n, vector<int>(2, 1))`)，其中:

`dp[i][0]`表示`arr[i]`為最後一個且`arr[i]`大於`arr[i-1]`之最長turbulent subarray長度。

`dp[i][1]`表示`arr[i]`為最後一個且`arr[i]`小於`arr[i-1]`之最長turbulent subarray長度。

在遍歷`arr`的過程中，我們的狀態轉移式如下:

`dp[i][0] = dp[i-1][1] + 1`, if `arr[i] > arr[i-1]`

`dp[i][1] = dp[i-1][0] + 1`, if `arr[i] < arr[i-1]`

代表當前`arr[i]`之DP解可接續`arr[i-1]`之相反符號之解，而過程中我們只要記錄最長的turbulent subarray長度，並於最後返回即可。