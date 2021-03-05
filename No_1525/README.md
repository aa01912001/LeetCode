題號: 1525. Number of Good Ways to Split a String

難度: Medium

## 問題描述
You are given a string `s`, a split is called good if you can split `s` into 2 non-empty strings `p` and `q` where its concatenation is equal to `s` and the number of distinct letters in `p` and `q` are the same.

Return the number of good splits you can make in `s`.

Example 1:

```
Input: s = "aacaba"
Output: 2
Explanation: There are 5 ways to split "aacaba" and 2 of them are good. 
("a", "acaba") Left string and right string contains 1 and 3 different letters respectively.
("aa", "caba") Left string and right string contains 1 and 3 different letters respectively.
("aac", "aba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aaca", "ba") Left string and right string contains 2 and 2 different letters respectively (good split).
("aacab", "a") Left string and right string contains 3 and 1 different letters respectively.
```

Constraints:

- `s` contains only lowercase English letters.
- `1 <= s.length <= 10^5`

---
## 解決思路

此題我們可利用`int rCount[26]`陣列先將`s`每個字元出現的次數計算出後，再從左到右遍歷分割字串，而再分割的過程中我們再利用`int lCount[26]`陣列即可將left substring每個字元出現過的次數計算出(**lCount中的某字元次數加1時，要將rCount中的相應字元次數減1**)，之後再比較`lCount`與`rCount`相異字元個數是否相同來確認此次是否為good split。