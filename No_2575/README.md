題號: 2575. Find the Divisibility Array of a String

難度: Medium

## 問題描述
You are given a **0-indexed** string `word` of length `n` consisting of digits, and a positive integer `m`.

The **divisibility array** `div` of `word` is an integer array of length `n` such that:

- `div[i] = 1` if the numeric value of `word[0,...,i]` is divisible by `m`, or
- `div[i] = 0` otherwise.

Return the divisibility array of `word`.

**Example 1:**
```
Input: word = "998244353", m = 3
Output: [1,1,0,0,0,1,1,0,0]
Explanation: There are only 4 prefixes that are divisible by 3: "9", "99", "998244", and "9982443".

```

**Constraints:**

- `1 <= n <= 10^5`
- `word.length == n`
- `word` consists of digits from `0` to `9`
- `1 <= m <= 10^9`

**解決思路:**

我們可以初始化一個變數`remainder = 0`，代表`word[0] ~ word[i-1]`除以`m`的餘數，下次計算`word[0] ~ word[i]`是否能被`m`整除時，我們只需要判斷`remainder * 10 + word[i]`是否能`m`被整除即可。