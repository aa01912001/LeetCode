題號: 509. Fibonacci Number

難度: Easy

## 問題描述
The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,


```
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```
Given `n`, calculate `F(n)`.

Example 1:
```
Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

Constraints:

- `0 <= n <= 30`



---
## 解決思路
此題只需維護一個陣列以DP的方式儲存每個`F(n)`即可利用先前計算過的歷史來求得當前Fibonacci number。