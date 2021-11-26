題號: 394. Decode String

難度: Medium

## 問題描述

Given an encoded string, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the `encoded_string` inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, `k`. For example, there won't be input like `3a` or `2[4]`.

**Example 1:**

```
Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"
```

**Constraints:**

- `1 <= s.length <= 30`
- `s` consists of lowercase English letters, digits, and square brackets `'[]'`.
- `s` is guaranteed to be **a valid** input.
- All the integers in `s` are in the range `[1, 300]`.

---
## 解決思路

此題我們可以從`s`頭到尾遍歷一遍，當我們遇到非`]`的字元，就將之丟入`stack<char>`中，否則就進行以下處理:

1. 從stack中取出`[`與`]`之間的字串
2. 取出位於前個`[`之前的整數字串
3. 根據此整數造出第1步驟所取出的字串之重複字串
4. 將第3步驟造出字串放入stack中

如此操作到最後，stack中的字元串聯起來即為解答。











