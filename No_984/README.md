題號: 984. String Without AAA or BBB

難度: Medium

## 問題描述

Given two integers `a` and `b`, return **any** string `s` such that:

- `s` has length `a + b` and contains exactly `a` `'a'` letters, and exactly `b` `'b'` letters,
- The substring `'aaa'` does not occur in `s`, and
- The substring `'bbb'` does not occur in `s`.

**Example 1:**
```
Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
```

**Constraints:**

- `0 <= a, b <= 100`
- It is guaranteed such an `s` exists for the given `a` and `b`.

---
## 解決思路

此題可使用Greedy的策略永遠讓'a'在符合下列兩個條件時優先進行插入：

1. 當'b'已經連續插入兩個時
2. 'a'尚未連續插入兩個且剩餘各數大於等於'b'

如此即可得到一組字串解

