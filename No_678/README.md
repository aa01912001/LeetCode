題號: 678. Valid Parenthesis String
難度: Medium

## 問題描述

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` if `s` is **valid**.

The following rules define a **valid** string:

- Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.
- Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.
- Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.
- `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

**Example 1:**
```
Input: s = "(*))"
Output: true
```

**Constraints:**

- `1 <= s.length <= 100`
- `s[i]` is `'('`, `')'` or `'*'`.


---
## 解決思路

此題我們只需要在分別由左至右與由右至左遍歷`s`兩次，遍歷途中計錄左括弧(`left`)、右括弧(`right`)與星號(`star`)的個數，由左至右遍歷的過程中只要我們發現`left + star < right`，則代表右括弧沒有辦法被匹配完全，因此返回`false`，而由右至左遍歷亦為相同道理。