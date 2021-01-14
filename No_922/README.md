題號: 922. Sort Array By Parity II

難度: Easy

## 問題描述
Given an array `A` of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever `A[i]` is odd, `i` is odd; and whenever `A[i]` is even, `i` is even.

You may return any answer array that satisfies this condition.

Example 1:
```
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
```

Note:

1. `2 <= A.length <= 20000`
2. `A.length % 2 == 0`
3. `0 <= A[i] <= 1000`

---
## 解決思路
此題我們使用`odd`與`even`兩個指標分別由前往後來查找A中位在奇數位置的偶數與位在偶數位置的奇數，找到這兩個數後就交換之。之後再依序往後查找交換即可。