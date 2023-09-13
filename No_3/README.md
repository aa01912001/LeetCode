題號: 3. Longest Substring Without Repeating Characters
難度: Medium

## 問題描述
Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```

**Constraints:**

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols and spaces.

## 解決思路
此題我們只需要採用sliding window策略，配合hash table來記錄當前window內不同字元的個數即可。

若當前字元的個數超過1，我們就應該縮進左窗口，直到此字元數量等於1，否則右移右窗口尋求更長的可能性。