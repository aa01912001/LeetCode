題號: 231. Power of Two

難度: Easy

## 問題描述
Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2^x`.

**Example 1:**
```
Input: n = 16
Output: true
Explanation: 24 = 16
```

**Constraints:**

- `-2^31 <= n <= 2^31 - 1`

**解決思路:**

此題我們只需要判斷`n`的binary形式是否只存在一個1即可。