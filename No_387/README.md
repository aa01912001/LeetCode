題號: 387. First Unique Character in a String

難度: Easy

## 問題描述

Given a string `s`, find the first non-repeating character in it and return its index. If it does not exist, return `-1`.

**Example 1:**


```
Input: s = "leetcode"
Output: 0
```


**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only lowercase English letters.





---
## 解決思路

此題只要先將`s`中所有字元的出現次數統計下來後，再從頭開始找出次數為1的字元即可。



