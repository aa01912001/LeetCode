題號: 20. Valid Parentheses
難度: Easy

## 問題描述
Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

**Example 1:**
```
Input: s = "()[]{}"
Output: true
```
**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of parentheses only `'()[]{}'`.

## 解決思路
此題我們只需要利用stack來存放先前的左括弧系列即可。

一旦我們遇到`'('`、`'['`、`'{'`，就將其放入stack中，而當前`s[i]`若是右括弧系列，則比對stack top是否匹配，若不匹配則直接返回false。

最後我們只需要判斷stack是否為空即可。
