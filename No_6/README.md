題號: 6. Zigzag Conversion

難度: `Medium`

## 問題描述

The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this:  
*(you may want to display this pattern in a fixed font for better legibility)*

```
P   A   H   N
A P L S I I G
Y   I   R
```

And then read line by line: `"PAHNAPLSIIGYIR"`

Write the code that will take a string and make this conversion given a number of rows:

`string convert(string s, int numRows);`

**Example 1:**
```
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
```
**Constraints:**

- `1 <= s.length <= 1000`
- `s` consists of English letters (lower-case and upper-case), `','` and `'.'`.
- `1 <= numRows <= 1000`

**解決思路:**

此題我們只需要模擬 Zigzag 的路徑走，把字一個一個丟進對應的 row，最後再把每一 row 接起來即可。