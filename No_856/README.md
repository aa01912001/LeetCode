題號: 856. Score of Parentheses

難度: Medium

## 問題描述
Given a balanced parentheses string `S`, compute the score of the string based on the following rule:

- `()` has score 1
- `AB` has score `A + B`, where A and B are balanced parentheses strings.
- `(A)` has score `2 * A`, where A is a balanced parentheses string.


Example 1:

```
Input: "()"
Output: 1
```

Example 2:

```
Input: "(()(()))"
Output: 6
```

Constraints:

 1. `S` is a balanced parentheses string, containing only `(` and `)`.
 2. `2 <= S.length <= 50`



---
## 解決思路
此題利用stack來存入左括弧(程式中用-1表示)，假如遇到右括弧後就要從top開始找左括弧，在找左括弧的期間如果遇到連續的數字，就要把它們相加暫存起來(程式中存在tmp變數)，找到左括弧後就把剛剛暫存的數字乘上2(規則3)後push到stack中。

最後檢查stack中是否還有數字，若有則將這些數字相加後則為答案。
