題號: **32. Longest Valid Parentheses**

難度: Hard

## 問題描述

Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.

**Example 1:**
```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```

**Constraints:**

- `0 <= s.length <= 3 * 10^4`
- `s[i]` is `'('`, or `')'`.

---
## 解決思路

此題可利用`stack<int>`來儲存合法**parentheses substring**的前一個位置，所以一開始我們必須先將-1放入stack中，在遍歷字串時，可以分為兩個位置:

1. 遇到`'('`:
    將此位置索引值放入stack中。
    
2. 遇到`')'`:
    若發現stack size為1，代表前面已無`'('`可以進行配對，因此當前索引值是一個新的開始，我們將此索引值放入stack中。
    若stack size不為1，代表我們可以將前一個`')'`取出進行配對，因此執行`stack.pop()`，並更新解答(`ret = max(ret, 當前索引-stk.top())`)。
    
如此遍歷字元到最後，返回`ret`即可。