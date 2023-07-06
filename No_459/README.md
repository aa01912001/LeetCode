題號: 459. Repeated Substring Pattern
難度: Easy

## 問題描述
Given a string `s`, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

**Example 1:**
```
Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.
```
**Constraints:**

- `1 <= s.length <= 10^4`
- `s` consists of lowercase English letters.

## 解決思路
此題首先我們可以思考我們如何判斷一個字串`T`是否為一個字串`S`經過rotate的形式?
判斷方式為去檢查`S`是否存在於`T+T`中。

假設`S`為一個由長度為`n`的pattern所構成的字串，代表其經由rotate `n`次後同樣等於自己。因此我們只要確認`S`是否存在於`(S+S)[1:-1]`即可判斷`S`是否符合題目所要求的字串。


