題號: 1539. Kth Missing Positive Number

難度: Easy

## 問題描述

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

Find the `kth` positive integer that is missing from this array.

**Example 1:**

```
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
```

Constraints:

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j] for 1 <= i < j <= arr.length`

---
## 解決思路

此題我們可以去計算arr中元素之間的差，再將k減去此差值，一旦發現k <= 0則代表答案位於`arr[i]~arr[i-1]`之間，只要將`arr[i]`加上減去差值之前的k即為答案。
