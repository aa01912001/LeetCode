題號: 1218. Longest Arithmetic Subsequence of Given Difference
難度: Medium

## 問題描述
Given an integer array `arr` and an integer `difference`, return the length of the longest subsequence in `arr` which is an arithmetic sequence such that the difference between adjacent elements in the subsequence equals `difference`.

A **subsequence** is a sequence that can be derived from `arr` by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**
```
Input: arr = [1,5,7,8,5,3,4,2,1], difference = -2
Output: 4
Explanation: The longest arithmetic subsequence is [7,5,3,1].
```

**Constraints:**

- `1 <= arr.length <= 10^5`
- `-10^4 <= arr[i], difference <= 10^4`

## 解決思路
此題我們只需要利用hash map以DP的方式記錄每個當前元素為尾端元素的最長長度即可。

再迭代的過程中，對於每個`arr[i]`，我們需要去檢查`arr[i] - difference`(代表subsequence中的前一個元素 )，是否存在於map中，若存在，則將當前`arr[i]`的DP值存為`arr[i] - difference`的DP值加1，否則為1。