題號: 1653. Minimum Deletions to Make String Balanced

難度: Medium

## 問題描述

You are given a string `s` consisting only of characters `'a'` and `'b'`.

You can delete any number of characters in `s` to make `s` **balanced**. `s` is **balanced** if there is no pair of indices `(i,j)` such that `i < j` and `s[i] = 'b'` and `s[j]= 'a'`.

Return the **minimum** number of deletions needed to make `s` balanced.

**Example 1:**
```
Input: s = "aababbab"
Output: 2
Explanation: You can either:
Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is `'a'` or `'b'`.

---
## 解決思路

此題可利用DP的策略來考慮每個`s[i]`的位置，對於每個`s[i]`來說，我們需要分為兩個cases:

1. `s[i] == 'b'`:
    由於最後一個char為`'b'`，所以絕對不會違反規則，因此若`s[0]~s[i-1]`已經為最佳解，那麼`s[0]~s[i]`的最少刪除次數等同於`s[0]~s[i-1]`之解。
    
2. `s[i] == 'a'`:
    此時`s[0]~s[i]`所需要刪除的次數為`s[0]~s[i-1]`之解加1(此加1為刪除`s[i]`)與`s[0]~s[i-1]`之`'b'`的個數取最小值。
    相當於考慮`s[i]`被刪除或沒刪除之情況
    
如此從頭考慮到最後即可得到最終解。