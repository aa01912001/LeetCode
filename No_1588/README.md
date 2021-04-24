題號: 1588. Sum of All Odd Length Subarrays

難度: Easy

## 問題描述
Given an array of positive integers `arr`, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of `arr`.

Example 1:

```
Input: arr = [1,4,2,5,3]
Output: 58
Explanation: The odd-length subarrays of arr and their sums are:
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
If we add all these together we get 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
```

Constraints:

- `1 <= arr.length <= 100`
- `1 <= arr[i] <= 1000`



---
## 解決思路

此題我們先將`arr`中的每個數字累加起來(例如: arr[i]儲存arr[0]+arr[1]+...+arr[i])。之後針對每個奇數子陣列(i,j)我們只要將(arr[j]-arr[i-1])累加至欲返回的結果即可。
