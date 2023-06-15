題號: 214. Shortest Palindrome
難度: Hard

## 問題描述
You are given a string `s`. You can convert `s` to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

**Example 1:**
```
Input: s = "aacecaaa"
Output: "aaacecaaa"
```
**Constraints:**

- `0 <= s.length <= 5 * 10^4`
- `s` consists of lowercase English letters only.

## 解決思路
此題我們只需要找出`s`最大回文前綴部分後，再把剩餘部分做reverse後，放在`s`前即可。

舉例來說 s = "abaccde"，其最大回文前綴為"aba"，因此剩餘部分"ccde"需要我們另外加字元於`s`前以構成整體回文"edccabaccde"

而我們可以首先建構一字串`s + "@" + reverse(s)`，以上例來說為"abaccde@edccaba"。
之後我們利用KMP演算法中的next來找出該字串最大共同前綴後綴，即可得到`s`的最大回文前綴部分。