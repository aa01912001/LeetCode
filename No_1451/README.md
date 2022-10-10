題號: 1451. Rearrange Words in a Sentence
難度: Medium

## 問題描述

Given a sentence `text` (A sentence is a string of space-separated words) in the following format:

- First letter is in upper case.
- Each word in `text` are separated by a single space.

Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange them in their original order.

Return the new text following the format shown above.

**Example 1:**
```
Input: text = "Keep calm and code on"
Output: "On and keep calm code"
Explanation: Output is ordered as follows:
"On" 2 letters.
"and" 3 letters.
"keep" 4 letters in case of tie order by position in original text.
"calm" 4 letters.
"code" 4 letters.
```

**Constraints:**

- `text` begins with a capital letter and then contains lowercase letters and single space between words.
- `1 <= text.length <= 10^5`


---
## 解決思路

此題我們先將`text`先將依照空白字元做切割並存入`vector<string>`之後，在使用內建的`stable_sort`進行排序以便讓長度相同的word維持相同的順序，最後再將排序好的words依規則進行大小寫轉換與結合成一個字串即可。