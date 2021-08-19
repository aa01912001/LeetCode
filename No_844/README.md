題號: 844. Backspace String Compare

難度: Easy

## 問題描述

Given two strings `s` and `t`, return `true` if they are equal when both are typed into empty text editors. `'#'` means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

**Example 1:**

```
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
```

**Constraints:**

- `1 <= s.length, t.length <= 200`
- `s` and `t` only contain lowercase letters and `'#'` characters.



---
## 解決思路

此題只要利用stack將s與t中的'#'字元進行處理過後再比較兩個新字串是否相同即可。


