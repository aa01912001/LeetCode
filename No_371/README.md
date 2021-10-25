題號: 371. Sum of Two Integers

難度: Medium

## 問題描述

Given two integers `a` and `b`, return the sum of the two integers without using the operators `+` and `-`.

**Example 1:**

```
Input: a = 1, b = 2
Output: 3
```

**Constraints:**

- `-1000 <= a, b <= 1000`


---
## 解決思路

此題我們計算每一回合的各位元的進位與加總來算出解答。在每一回合中，我們將`a`與`b`做
`&`運算並向左位移一位後存於`carry`變數中，即可得到當前各位元加總後的進位，同時將`a`與`b`做`xor`運算並存數`sum`中來得到當下的和。在之後的回合中就將`carry`當成`a`，`sum`當成`b`重複上述步驟直到`carry`等於0即可結束返回`sum`。






