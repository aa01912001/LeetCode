題號: 150. Evaluate Reverse Polish Notation
難度: Medium

## 問題描述

Evaluate the value of an arithmetic expression in `Reverse Polish Notation`.

Valid operators are `+`, `-`, `*`, and `/`. Each operand may be an integer or another expression.

**Note** that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

**Example 1:**
```
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
```
**Constraints:**

- `1 <= tokens.length <= 10^4`
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

---
## 解決思路

此題我們只要利用stack來儲存每個operand即可，只要當前`tokens[i]`為數字我們就將其放入stack中，反之若當前`tokens[i]`為operator，我們則從stack中取出前兩個operand做此operator運算後，再將結果存入stack中，因此，最後stack所留存的數即為解答。
