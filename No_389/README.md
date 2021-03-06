題號: 389. Find the Difference

難度: Easy

## 問題描述
You are given two strings `s` and `t`.

String `t` is generated by random shuffling string `s` and then add one more letter at a random position.

Return the letter that was added to `t`.

Example 1:

```
Input: s = "abcd", t = "abcde"
Output: "e"
Explanation: 'e' is the letter that was added.
```

Constraints:

- `0 <= s.length <= 1000`
- `t.length == s.length + 1`
- `s` and `t` consist of lower-case English letters.

---
## 解決思路

此題我們可以利用一個初始化變數`int ret = 0;`，將之與所有`s`、`t`中的所有字元做xor運算，即可得到目標字元的ascii碼。
