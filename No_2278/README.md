題號: 2278. Percentage of Letter in String

難度: `Easy`

## 問題描述

Given a string `s` and a character `letter`, return the percentage of characters in `s` that equal `letter` rounded down to the nearest whole percent.

**Example 1:**
```
Input: s = "foobar", letter = "o"
Output: 33
Explanation:
The percentage of characters in s that equal the letter 'o' is 2 / 6 * 100% = 33% when rounded down, so we return 33.
```
**Constraints:**

- `1 <= s.length <= 100`
- `s` consists of lowercase English letters.
- `letter` is a lowercase English letter.

**解決思路:**

直接計算`letter`出現次數即可，再算出頻率即可。