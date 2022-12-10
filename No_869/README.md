題號: 869. Reordered Power of 2
難度: Medium

## 問題描述
You are given an integer `n`. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return `true` if and only if we can do this so that the resulting number is a power of two.

**Example 1:**
```
Input: n = 10
Output: false
```

**Constraints:**

- `1 <= n <= 10^9`

---
## 解決思路

此題因為`n`的範圍有限制，因此我們可以將所有`1~2^30`之間的所有2的次方轉換成字串後進行排序，並與`n`的數字字串排序進行比較，若相同則代表`n`可以被轉換為該2的次方數，因此返回true。