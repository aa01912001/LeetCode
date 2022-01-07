題號: 990. Satisfiability of Equality Equations
難度: Medium

## 問題描述

You are given an array of strings `equations` that represent relationships between variables where each string `equations[i]` is of length `4` and takes one of two different forms: `"xi==yi"` or `"xi!=yi"`.Here, `xi` and `yi` are lowercase letters (not necessarily different) that represent one-letter variable names.

Return `true` if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

**Example 1:**
```
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
```


**Constraints:**

- `1 <= equations.length <= 500`
- `equations[i].length == 4`
- `equations[i][0]` is a lowercase letter.
- `equations[i][1]` is either `'='` or `'!'`.
- `equations[i][2]` is `'='`.
- `equations[i][3]` is a lowercase letter.

---
## 解決思路

此題可藉由DSU方法來解，首先我們必須針對`"=="`的關係將兩個變數union為同一個group，之後再針對`"!="`關係來判斷兩個變數是否屬於同一個group，若是的話，則矛盾，因此回傳false。