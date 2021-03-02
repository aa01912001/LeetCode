題號: 263. Ugly Number

難度: Easy

## 問題描述
Write a program to check whether a given number is an ugly number.

Ugly numbers are **positive numbers** whose prime factors only include `2, 3, 5`.
Example 1:

```
Input: 6
Output: true
Explanation: 6 = 2 × 3
```

Note:


1. `1` is typically treated as an ugly number.
2. Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].


---
## 解決思路

此題首先先判斷`num`是否小於等於0，是的話則返回false(為ugly number必定為正整數)，否則將`num`分別連續整除2、3、5後判斷最後是否等於1即可。