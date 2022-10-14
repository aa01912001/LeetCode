題號: 1461. Check If a String Contains All Binary Codes of Size K
難度: Medium

## 問題描述

Given a binary string `s` and an integer `k`, return `true` if every binary code of length `k` is a substring of `s`. Otherwise, return `false`.

**Example 1:**
```
Input: s = "00110110", k = 2
Output: true
Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
```

**Constraints:**

- `1 <= s.length <= 5 * 10^5`
- `s[i]` is either `'0'` or `'1'`.
- `1 <= k <= 20`

---
## 解決思路

我們知道長度`k`的binary code共有`2^k`個不同的形式，因此此題只需要透過`unordered_set<string>`將所有`s`中長度為`k`的子字串放入其中，最後判斷該set的大小是否等於`2^k`即可。