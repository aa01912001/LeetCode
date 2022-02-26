題號: 1013. Partition Array Into Three Parts With Equal Sum
難度: Easy

## 問題描述

Given an array of integers arr, return `true` if we can partition the array into three **non-empty** parts with equal sums.

Formally, we can partition the array if we can find indexes `i + 1 < j` with `(arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1])`

**Example 1:**

```
Input: arr = [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
```

**Constraints:**

- `3 <= arr.length <= 5 * 10^4`
- `-10^4 <= arr[i] <= 10^4`

---
## 解決思路

此題要將array分為三個相同的區塊代表著每一區塊的和必定為`sum(array)/3`，假設此值為`target`後，我們再遍歷array一次並做累加，只要累加值等於`target`後，我們就將`count`加一，並重設累加值為0。只要最後`count`大於等於3即可返回`true`。

Note：`count`大於3也返回true的原因再於可能會有`[0,0,0,0]`這種特殊例子。

