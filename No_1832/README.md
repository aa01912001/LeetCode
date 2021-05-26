題號: 1832. Check if the Sentence Is Pangram

難度: Easy

## 問題描述

A **pangram** is a sentence where every letter of the English alphabet appears at least once.

Given a string `sentence` containing only lowercase English letters, return `true` if `sentence` is a **pangram**, or `false` otherwise.

Example 1:

```
Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.
```

Constraints:

- `1 <= sentence.length <= 1000`
- `sentence` consists of lowercase English letters.



---
## 解決思路

此題可以利用`unordered_set<char>`來儲存string中出現過的字元，最後判斷size是否等於26即可。