題號: 1837. Sum of Digits in Base K

難度: Easy

## 問題描述

Given an integer `n` (in base `10`) and a base `k`, return the **sum** of the digits of `n` `after` converting `n` from base `10` to base `k`.

After converting, each digit should be interpreted as a base `10` number, and the sum should be returned in base `10`.
**Example 1:**


```
Input: n = 34, k = 6
Output: 9
Explanation: 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.
```

**Constraints:**

- `1 <= n <= 100`
- `2 <= k <= 10`


---
## 解決思路

此題我們一直執行下方程式，直到n < k。

```
ret += n % k;
n = n / k;
```

最後返回`ret + n`即可。
