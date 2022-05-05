題號: 2063. Vowels of All Substrings
難度: Medium

## 問題描述

Given a string `word`, return the **sum of the number of vowels** (`'a'`, `'e'`, `'i'`, `'o'`, and `'u'`) in every substring of `word`.

A **substring** is a contiguous (non-empty) sequence of characters within a string.

**Note:** Due to the large constraints, the answer may not fit in a signed 32-bit integer. Please be careful during the calculations.

**Example 1:**
```
Input: word = "aba"
Output: 6
Explanation: 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
```
**Constraints:**

- `1 <= word.length <= 10^5`
- `word` consists of lowercase English letters.

---
## 解決思路

此題可以採用DP的方式來解決，我們令`dp[i]`為所有包含`word[i]`為最後字元子字串之解，因此我們可以輕易看出此DP的狀態轉移式為：

`dp[i] = dp[i-1] + i + 1`, if `word[i]` is a vowel.
i + 1為當前字元所造成之額外個數(`word[0]~word[i]`之子字串，`word[1]~word[i]`之子字串， ... ， `word[i]~word[i]`之子字串)。

`dp[i] = dp[i-1]`, otherwise.

最後我們只需要返回所有子字串之情況總和即可(也就是，`sum(dp[0], dp[1], ..., dp[n])`)




