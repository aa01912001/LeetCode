題號: 50. Pow(x, n)

難度: Medium

## 問題描述

Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `x^n`).

**Example 1:**

```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**

```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
```

**Constraints:**

- `-100.0 < x < 100.0`
- `-2^31 <= n <= 2^31-1`
- `-10^4 <= x^n <= 10^4`


---
## 解決思路

此題可利用遞迴的方式去遞迴計算`pow(x, n/2)`，並將得到的數自我相乘一次即可得到`pow(x, n)`。須注意當`n`為奇數時，需要額外再乘上`x`。
