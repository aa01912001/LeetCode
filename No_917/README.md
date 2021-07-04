題號: 917. Reverse Only Letters

難度: Easy

## 問題描述

Given a string `s`, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

**Example 1:**

```
Input: s = "ab-cd"
Output: "dc-ba"
```

**Note:**

1. `s.length <= 100`
2. `33 <= s[i].ASCIIcode <= 122 `
3. `s` doesn't contain `\` or `"`


---
## 解決思路

此題只需要利用`two pointers`的方式從前後依序找英文字母做交換即可。
