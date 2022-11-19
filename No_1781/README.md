題號: 1781. Sum of Beauty of All Substrings
難度: Medium

## 問題描述

The **beauty** of a string is the difference in frequencies between the most frequent and least frequent characters.

- For example, the beauty of `"abaacc"` is `3 - 1 = 2`.

Given a string `s`, return the sum of **beauty** of all of its substrings.

**Example 1:**
```
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
```

**Constraints:**

- `1 <= s.length <= 500`
- `s` consists of only lowercase English letters.

---
## 解決思路

此題我們只需要採用brute force的方式針對所有substring來計算最高與最低字元頻率後，將相減值加至解答中即可。