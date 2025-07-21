題號: 1957. Delete Characters to Make Fancy String

難度: Medium

## 問題描述
A **fancy string** is a string where no **three consecutive** characters are equal.

Given a string `s`, delete the **minimum** possible number of characters from `s` to make it **fancy**.

Return the final string after the deletion. It can be shown that the answer will always be **unique**.

**Example 1:**
```
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists only of lowercase English letters.

**解決思路:**

此題我們只需要透過stack不斷地從頭開始放入每個字元，但如果當前字元與前stack最上面兩個字元相同的話則不放入，最後我們只需要將stack的所有字元串接起來即可。