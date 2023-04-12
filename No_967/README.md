題號: 967. Numbers With Same Consecutive Differences
難度: Medium

## 問題描述
Given two integers n and k, return an array of all the integers of length `n` where the difference between every two consecutive digits is `k`. You may return the answer in **any order**.

Note that the integers should not have leading zeros. Integers as `02` and `043` are not allowed.

**Example 1:**
```
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
```

**Constraints:**

- `2 <= n <= 9`
- `0 <= k <= 9`

## 解決思路
此題我們只需要利用DFS的方式對每一個digit的後一個數字(digit+k與digit-k)進行遞迴建構即可。