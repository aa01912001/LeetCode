題號: 1003. Check If Word Is Valid After Substitutions
難度: Medium

## 問題描述

Given a string `s`, determine if it is **valid**.

A string `s` is **valid** if, starting with an empty string `t = ""`, you can **transform** `t` **into** `s` after performing the following operation **any number of times**:

- Insert string `"abc"` into any position in `t`. More formally, `t` becomes `tleft + "abc" + tright`, where `t == tleft + tright`. Note that `tleft` and `tright` may be **empty**.

Return `true` if `s` is a **valid** string, otherwise, return `false`.

**Example 1:**
```
Input: s = "aabcbc"
Output: true
Explanation:
"" -> "abc" -> "aabcbc"
Thus, "aabcbc" is valid.
```

**Constraints:**

- `1 <= s.length <= 2 * 10^4`
- `s` consists of letters `'a'`, `'b'`, and `'c'`

---
## 解決思路

此題相當於判斷是否可以從`s`每次刪去`"abc"`，使`s`最後變為`""`。

程式中我們使用`stack<char>`來儲存遍歷到的字元，一但我們碰上`'c'`就去判斷stack最上面兩個字元是否分別為`'b'`與`'a'`，若是的話，則代表遇到`"abc"`之pattern，我們就將其pop出來，否則將`'c'`放入stack中繼續進行判斷。

最後遍歷完所有字元後，若stack為空，則代表`t`為合法之`s`轉變而來，因此return true。

