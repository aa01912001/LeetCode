題號: 1400. Construct K Palindrome Strings

難度: Medium

## 問題描述
Given a string `s` and an integer `k`. You should construct `k` non-empty **palindrome** strings using **all the characters** in `s`.

Return **True** if you can use all the characters in `s` to construct `k` palindrome strings or **False** otherwise.

Example 1:

```
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
```
---
## 解決思路
首先我們先計算string s中所有字元各自的數量，再去判斷哪些字元的數量是奇數的，並加總這樣的字元有幾個，**加總後的數字(儲存在變數odd中)就代表這個string s最少一定有的palindrome strings個數**。

我們可以發現一個string s可以產生出的palindrome strings數量**範圍一定落在 odd ~ s.length() 區間(這個範圍內的palindrome strings都可以產生)**。最後我們只需判斷k是否落在這個區間即可。
