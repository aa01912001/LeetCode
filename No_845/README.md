題號: 845. Longest Mountain in Array

難度: Medium

## 問題描述

You may recall that an array `arr` is a **mountain array** if and only if:

- `arr.length >= 3`
- There exists some index `i` (**0-indexed**) with `0 < i < arr.length - 1` such that:
    - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
    - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given an integer array `arr`, return the length of the longest subarray, which is a mountain. Return `0` if there is no mountain subarray.

**Example 1:**

```
Input: arr = [2,1,4,7,3,2,5]
Output: 5
Explanation: The largest mountain is [1,4,7,3,2] which has length 5.
```

**Constraints:**

- `1 <= arr.length <= 10^4`
- `0 <= arr[i] <= 10^4`

---
## 解決思路

此題我們可利用兩個與`arr`長度相同的DP陣列，`leftDP`、`rightDP`來解決。

其中:

`leftDP[i]`儲存`arr[i]`左邊開始遞減的陣列長度
`rightDP[i]`儲存`arr[i]`右邊開始遞增的陣列長度

之後只要找出`leftDP[i]+rightDP[i]+1`最大的值即可。
