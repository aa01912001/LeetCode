題號: 1234. Replace the Substring for Balanced String

難度: Medium

## 問題描述
## Problem Description

You are given a string `s` of length `n` containing only four kinds of characters: `'Q'`, `'W'`, `'E'`, and `'R'`.

A string is said to be **balanced** if each of its characters appears `n / 4` times where `n` is the length of the string.

Return the *minimum length of the substring that can be replaced with any other string of the same length* to make `s` **balanced**.  
If `s` is already **balanced**, return `0`.

**Example 1:**
```
Example 3:

Input: s = "QQQW"
Output: 2
Explanation: We can replace the first "QQ" to "ER". 
```

**Constraints:**

- `n == s.length`
- `4 <= n <= 10^5`
- `n` is a multiple of `4`.
- `s` contains only `'Q'`, `'W'`, `'E'`, and `'R'`.

**解決思路:**

首先我們需要計算出那些冗於字元超出的數量，之後使用sliding window的方式開始尋找最短可替換的子字串。

每回合我們嘗試向右擴展右邊界還涵蓋多出來的字母，若目前窗口中已經「涵蓋」所有多出來的字母數量時，更新最短長度，之後開始不斷縮短左邊界直到沒辦法涵蓋為止。