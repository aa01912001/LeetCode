題號: 926. Flip String to Monotone Increasing

難度: Medium

## 問題描述

A binary string is monotone increasing if it consists of some number of `0`'s (possibly none), followed by some number of `1`'s (also possibly none).

You are given a binary string `s`. You can flip `s[i]` changing it from `0` to `1` or from `1` to `0`.

Return the minimum number of flips to make s monotone increasing.

**Example 1:**

```
Input: s = "00110"
Output: 1
Explanation: We flip the last digit to get 00111.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s[i]` is either `'0'` or `'1'`.

---
## 解決思路

此題我們首先計算給定字串中1的個數並存入`flips`變數中，並將返回值暫定為`flips`(代表將給定字串轉變成000...000最少需要的flip數)。

之後我們開始考慮將給定字串轉變成:

000...001、
000...011、
000...111、
.
.
.
111...111。

各需要多少的flip次數?

因此我們可以從字串後面遍歷回來，每當遇見'1'代表這個位置原本就有'1'所以不需要flip操作，故將`flips`減去1。若當前位置為'0'，代表需要執行flip操作使該位置變成'1'，因此將`flips`加1。而每回合結束後我們則比較當前`flips`是不是比上次更小，若是的話則代表目前有可能是最佳解，因此將返回值做更新。

Note: 每回合對於字串中的一個位置做判斷代表我們打造出了一個上述後綴皆為1的字串，而`flips`表示將原本字串遍為此後綴字串需要最少的flip次數。











