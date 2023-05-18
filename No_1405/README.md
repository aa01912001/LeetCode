題號: 1405. Longest Happy String
難度: Medium

## 問題描述
A string `s` is called **happy** if it satisfies the following conditions:

- `s` only contains the letters `'a'`, `'b'`, and `'c'`.
- `s` does not contain any of `"aaa"`, `"bbb"`, or `"ccc"` as a substring.
- `s` contains **at most** `a` occurrences of the letter `'a'`.
- `s` contains **at most** `b` occurrences of the letter `'b'`.
- `s` contains **at most** `c` occurrences of the letter `'c'`.

Given three integers `a`, `b`, and `c`, return the **longest possible happy** string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string `""`.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**
```
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
```
**Constraints:**

- `0 <= a, b, c <= 100`
- `a + b + c > 0`

## 解決思路
此題我們利用max heap，每次只挑出剩餘次數最大的字元做append即可。需注意的是我們每一回合要另外判斷挑出來的字元是否與前兩個字元相同，若相同，則挑選次大的字元(若無次大字元則直接返回當前字串)。