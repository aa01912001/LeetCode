題號: 1358. Number of Substrings Containing All Three Characters
難度: Medium

## 問題描述
Given a string `s` consisting only of characters a, b and c.

Return the number of substrings containing **at least** one occurrence of all these characters a, b and c.

**Example 1:**
```
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
```

**Constraints:**

- `3 <= s.length <= 5 x 10^4`
- `s` only consists of a, b or c characters.

---
## 解決思路
此題只需要利用sliding window配合hash map來記錄區間內的不同元素個數即可。

若區間內元素個數大於等於3個，我們將`s.length() - right`加入至解答中(因為right向右擴展之子字串也必定符合條件)，並且將`left`右移。

若區間內元素個數小於3個，將`right`右移繼續尋找符合的子字串。