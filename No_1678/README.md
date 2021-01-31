題號: 1678. Goal Parser Interpretation

難度: Easy

## 問題描述
You own a **Goal Parser** that can interpret a string `command`. The `command` consists of an alphabet of `"G"`, `"()"` and/or `"(al)"` in some order. The Goal Parser will interpret `"G"` as the string `"G"`, `"()"` as the string `"o"`, and `"(al)"` as the string `"al"`. The interpreted strings are then concatenated in the original order.

Given the string `command`, return the **Goal Parser**'s interpretation of `command`.

Example 1:

```
Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".
```

Constraints:


- `1 <= command.length <= 100`
- `command` consists of `"G"`, `"()"`, and/or `"(al)"` in some order.




---
## 解決思路
此題只需遍歷`command`中的每個字元，並利用if條件式來判斷interpret的決策即可。細節直接看程式碼!!