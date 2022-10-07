題號: 1447. Simplified Fractions
難度: Medium

## 問題描述

Given an integer `n`, return a list of all **simplified** fractions between `0` and `1` (exclusive) such that the denominator is less-than-or-equal-to `n`. You can return the answer in **any order**.

**Example 1:**
```
Input: n = 4
Output: ["1/2","1/3","1/4","2/3","3/4"]
Explanation: "2/4" is not a simplified fraction because it can be simplified to "1/2".
```

**Constraints:**

- `1 <= n <= 100`

---
## 解決思路

此題我們只需要透過brute force的方法判斷分母與分子是否為互質即可，若GCD為1則為最簡分數，將其放入置解答中；另外我們讓分母為`2~n`，假設分母當前為`i`，則分子則應該為`1~i-1`。