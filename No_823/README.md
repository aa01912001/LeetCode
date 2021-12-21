題號: 823. Binary Trees With Factors

難度: Medium

## 問題描述

Given an array of unique integers, `arr`, where each integer `arr[i]` is strictly greater than `1`.

We make a binary tree using these integers, and each number may be used for any number of times. Each non-leaf node's value should be equal to the product of the values of its children.

Return the number of binary trees we can make. The answer may be too large so return the answer **modulo** `10^9 + 7`.

**Example 1:**
```
Input: arr = [2,4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
```


**Constraints:**

- `1 <= arr.length <= 1000`
- `2 <= arr[i] <= 10^9`
- All the values of `arr` are **unique**.

---
## 解決思路

此題可利用DP的策略來解。

首先我們需要將`arr`做遞增排序後，再依序考慮每個`arr[i]`作為root可能造出的binary tree個數。

對於`arr[i]`來說，必須從`arr[0]~arr[i-1]`中找出兩數`arr[j]`與`arr[k]`，使得`arr[j]*arr[k] = arr[i]`，如此就能把`arr[i]`作為root可能造出的binary tree個數加上:
- `arr[j]`作為root時可能的binary tree個數乘上`arr[k]`作為root時可能的binary tree個數。

因此在程式中，我們使用`unordered_map<int, long long int> dp;`的結構將每個`nums[i]`作為root時的binary tree個數紀錄其中，如此只要最後將所有dp中的binary tree數量相加即為正確答案。

**Note:** 每個`dp[arr[i]]`需要另外加1，以便將只有一個自身為root的節點之情況考慮進去。