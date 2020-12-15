題號: 22. Generate Parentheses

難度: Medium

## 問題描述
Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```
---
## 解決思路
此題用遞迴去解，讓左括弧先放之後再放右括弧，直到左括弧與右刮弧數量都用完後再把形成的string放入解答中。

Note: 程式中的 **if(left < right)** 是為了防止遞迴中可能發生先放右括弧的數量多於左括弧的數量之情形。
