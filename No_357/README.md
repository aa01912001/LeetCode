題號: 357. Count Numbers with Unique Digits

難度: Medium

## 問題描述

Given an integer `n`, return the count of all numbers with unique digits, `x`, where `0 <= x < 10^n`.

**Example 1:**

```
Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
```

**Constraints:**

- `0 <= n <= 8`

---
## 解決思路

此題我們需要將數字等於不同位數時分開討論，舉例來說當數字10~99時，那麼這個範圍內應該被加入解答中的個數為**所有digit不同的數量減去第一個digit為0且後面皆不同之個數(i.e 10x9-9)**，藉由分段討論後並相加階段解後，即可得到最終解答。
