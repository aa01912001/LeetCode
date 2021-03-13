題號: 1780. Check if Number is a Sum of Powers of Three

難度: Medium

## 問題描述
Given an integer `n`, return `true` if it is possible to represent `n` as the sum of distinct powers of three. Otherwise, return `false`.

An integer `y` is a power of three if there exists an integer `x` such that `y == 3^x`.

Example 1:

```
Input: n = 12
Output: true
Explanation: 12 = 3^1 + 3^2
```

Constraints:

- `1 <= n <= 10^7`


---
## 解決思路

此題只要先計算出離n最近的3的次方數(假設為x)後，再利用遞迴的方式依序將n值減去3^(x-1)，之後判斷最後是否可以成功減到0。

**Note: n值減去3^(x-1) 時需要判斷3^(x-1)是否大於n值。**