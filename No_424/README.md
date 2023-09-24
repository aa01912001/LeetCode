題號: 424. Longest Repeating Character Replacement
難度: Medium

## 問題描述
You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

**Example 1:**
```
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
```

**Constraints:**

- `1 <= s.length <= 10^5`
- `s` consists of only uppercase English letters.
- `0 <= k <= s.length`

## 解決思路
此題我們透過sliding window的方式配合hash map紀錄當前window內每個字元的count數量。

假設當前window內最大的某個最大字元數量為`maxFreq`，若我們發現window長度減去`maxFreq`大於`k`，則代表無法負荷，我們應該右移左窗口，否則右移右窗口尋求更大的可能性。