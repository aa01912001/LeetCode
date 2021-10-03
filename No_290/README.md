題號: 290. Word Pattern

難度: Easy

## 問題描述

Given a `pattern` and a string `s`, find if `s` follows the same pattern.

Here **follow** means a full match, such that there is a bijection between a letter in `pattern` and a **non-empty** word in `s`.

**Example 1:**

```
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
```

**Constraints:**

- `1 <= pattern.length <= 300`
- `pattern` contains only lower-case English letters.
- `1 <= s.length <= 3000`
- `s` contains only lower-case English letters and spaces `' '`.
- `s` **does not contain** any leading or trailing spaces.
- All the words in `s` are separated by a **single space**.


---
## 解決思路

此題我們首先將`s`做split後，再用`unordered_map<string, char>`來記錄每個word與pattern字元的對應關係，如此只要遍歷一次就可以知道`s`是否符合pattern了。


