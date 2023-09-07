題號: 383. Ransom Note
難度: Easy

## 問題描述
Given two strings `ransomNote` and `magazine`, return `true` if `ransomNote` can be constructed by using the letters from `magazine` and `false` otherwise.

Each letter in `magazine` can only be used once in `ransomNote`.

**Example 1:**
```
Input: ransomNote = "aa", magazine = "aab"
Output: true
```

**Constraints:**

- `1 <= ransomNote.length, magazine.length <= 10^5`
- `ransomNote` and `magazine` consist of lowercase English letters.

## 解決思路
此題我們只要使用hash table來記錄`ransomNote`與`magazine`的字元個數，並判斷`ransomNote`每個所需的字元數量是否都小於等於在`magazine`中相應的字元數量即可。
