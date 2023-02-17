題號: 1541. Minimum Insertions to Balance a Parentheses String
難度: Medium

## 問題描述
Given a parentheses string `s` containing only the characters `'('` and `')'`. A parentheses string is **balanced** if:

- Any left parenthesis `'('` must have a corresponding two consecutive right parenthesis `'))'`.
- Left parenthesis `'('` must go before the corresponding two consecutive right parenthesis `'))'`.

In other words, we treat `'('` as an opening parenthesis and `'))'` as a closing parenthesis.

- For example, `"())"`, `"())(())))"` and `"(())())))"` are balanced, `")()"`, `"()))"` and `"(()))"` are not balanced.

You can insert the characters `'('` and `')'` at any position of the string to balance it if needed.

Return the minimum number of insertions needed to make `s` balanced.

**Example 1:**
```
Input: s = "(()))"
Output: 1
Explanation: The second '(' has two matching '))', but the first '(' has only ')' matching. We need to add one more ')' at the end of the string to be "(())))" which is balanced.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of `'('` and `')'` only.

---
## 解決思路
此題我們只需要由左至右掃描整個string，並記錄左括號與右括號出現的情況以便考慮新增的個數即可。

須注意連續奇數個右括弧的處理方式。