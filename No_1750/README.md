題號: 1750. Minimum Length of String After Deleting Similar Ends
難度: Medium

## 問題描述
Given a string `s` consisting only of characters `'a'`, `'b'`, and `'c'`. You are asked to apply the following algorithm on the string any number of times:

- 1. Pick a **non-empty** prefix from the string `s` where all the characters in the prefix are equal.
- 2. Pick a **non-empty** suffix from the string `s` where all the characters in this suffix are equal.
- 3. The prefix and the suffix should not intersect at any index.
- 4. The characters from the prefix and suffix must be the same.
- 5. Delete both the prefix and the suffix.

Return the **minimum length** of `s` after performing the above operation any number of times (possibly zero times).

**Example 1:**
```
Input: s = "cabaabac"
Output: 0
Explanation: An optimal sequence of operations is:
- Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
- Take prefix = "a" and suffix = "a" and remove them, s = "baab".
- Take prefix = "b" and suffix = "b" and remove them, s = "aa".
- Take prefix = "a" and suffix = "a" and remove them, s = "".
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` only consists of characters `'a'`, `'b'`, and `'c'`.

---
## 解決思路
此題只需要利用two pointers的方式，找出左邊連續相同的子字串，與右邊連續相同的子字串後，再判斷兩邊字元是否相同，若相同則將`s`削減去左右子字串的部分後再往下尋找，否則直接中止並返回當前子字串長度即可。