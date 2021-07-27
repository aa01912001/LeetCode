題號: 58. Length of Last Word

難度: Easy

## 問題描述

Given a string `s` consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return `0`.

A **word** is a maximal substring consisting of non-space characters only.

**Example 1:**


```
Input: s = "Hello World"
Output: 5
```


**Constraints:**

- `1 <= s.length <= 104`
- `s` consists of only English letters and spaces `' '`.


---
## 解決思路

此題我們可利用`stringstream`做字串分割後，再得到最後一個word的長度。



