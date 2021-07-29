題號: 1910. Remove All Occurrences of a Substring

難度: Medium

## 問題描述

Given two strings `s` and `part`, perform the following operation on `s` until **all** occurrences of the substring `part` are removed:

- Find the **leftmost** occurrence of the substring `part` and **remove** it from `s`.

Return `s` after removing all occurrences of `part`.

A **substring** is a contiguous sequence of characters in a string.

**Example 1:**


```
Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explanation: The following operations are done:
- s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
- s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
- s = "dababc", remove "abc" starting at index 3, so s = "dab".
Now s has no occurrences of "abc".
```


**Constraints:**

- `1 <= s.length <= 1000`
- `1 <= part.length <= 1000`
- `s` and `part` consists of lowercase English letters.




---
## 解決思路

此題我們可利用`stack<char>`將遍歷過的字元儲存起來，當遍歷到跟`part`最後一個字元一樣的字元後，就利用`stack<char>`向前比較即可。



