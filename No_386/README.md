題號: 386. Lexicographical Numbers
難度: Medium

## 問題描述

Given an integer `n`, return all the numbers in the range `[1, n]` sorted in lexicographical order.

You must write an algorithm that runs in `O(n)` time and uses `O(1)` extra space. 

**Example 1:**
```
Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
```

**Constraints:**

- `1 <= n <= 5 * 10^4`

---
## 解決思路

此題我們可使用Backtracking的策略依序將0至9加入至`num`(表示當前的累加加總)中，一但發現`num`大於`n`，即中止遞迴，否則就將當前的`num`放入解答中，並將`num`乘上10後進入下一層遞迴。

