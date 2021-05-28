題號: 1362. Closest Divisors

難度: Medium

## 問題描述

Given an integer `num`, find the closest two integers in absolute difference whose product equals `num + 1` or `num + 2`.

Return the two integers in any order.

Example 1:

```
Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
```

Constraints:

- 1 <= num <= 10^9



---
## 解決思路

此題我們可將`num+1`與`num+2`作開根號後來從1\~sqrt(num+1)或是1\~sqrt(num+2)做迭代來尋找divisors，最後再比較哪個解的絕對差值比較小並回傳即可。