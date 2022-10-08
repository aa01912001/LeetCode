題號: 1249. Minimum Remove to Make Valid Parentheses
難度: Medium

## 問題描述

Given a string s of `'('` , `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting parentheses string is valid and return **any** valid string.

Formally, a parentheses string is valid if and only if:

- It is the empty string, contains only lowercase characters, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or
- It can be written as `(A)`, where `A` is a valid string.

**Example 1:**
```
Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either`'('` , `')'`, or lowercase English letter.

---
## 解決思路

此題我們可透過stack來儲存不必要的左括弧位置，在遍歷的過程中若發現stack為空且當前為右括弧，代表此右括弧為非法，我們將之變為`s[i] = '$'`作為標記，否則從stack中pop出一左括弧與之配對，一旦遍歷完後，我們將所有stack中剩餘的非法左括弧對應位置也標記為`'$'`，之後將所有`s`中的`'$'`字元挑出形成最終解答。