題號: 1328. Break a Palindrome
難度: Medium

## 問題描述

Given a palindromic string of lowercase English letters `palindrome`, replace **exactly one** character with any lowercase English letter so that the resulting string is **not** a palindrome and that it is the **lexicographically smallest** one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an **empty string**.

A string `a` is lexicographically smaller than a string `b` (of the same length) if in the first position where `a` and `b` differ, `a` has a character strictly smaller than the corresponding character in `b`. For example, `"abcc"` is lexicographically smaller than `"abcd"` because the first position they differ is at the fourth character, and `'c'` is smaller than `'d'`.

**Example 1:**
```
Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
Of all the ways, "aaccba" is the lexicographically smallest.
```
**Constraints:**

- `1 <= palindrome.length <= 1000`
- `palindrome` consists of only lowercase English letters.

---
## 解決思路

此題我們可以透過以下三條規則來完成：

1. 唯一讓palindrome無法被break的case只有當字串長度為1的時候才有可能發生，因此程式中若發現字串長度為1，即返回""。

2. 當字串中的字元全為'a'時，只需要將最後一個字元變為'b'即為lexicographically smallest之解。

3. 扣除規則1、2的以外的字串形式，我們只需要把從左邊開始數的第一個不為'a'的字元變為'a'即可。

我們在程式中只需要判斷輸入字串屬於上述三條規則的哪一種形式，並按照規則進行處理即可。

