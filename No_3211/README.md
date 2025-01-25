題號: 3211. Generate Binary Strings Without Adjacent Zeros
難度: Medium

## 問題描述
You are given a positive integer `n`.

A binary string `x` is **valid** if all
**substrings**
of `x` of length 2 contain **at least** one `"1"`.

Return all **valid** strings with length `n`, in any order. such walk return `-1`.

**Example 1:**
```
Input: n = 3

Output: ["010","011","101","110","111"]

Explanation:

The valid strings of length 3 are: "010", "011", "101", "110", and "111".

```

**Constraints:**

- `1 <= n <= 18`

**解決思路:**
此題我們可以透過backtracking來窮舉生成所有可能的字串。

對於一個當前的字串`s`，我們判斷若其最後一個字元以及倒數第二個字元皆為2的話，我們則返回，中斷該遞迴分支。否則若當前`s`長度已經為`n`的話，我們則將當前的`s`放入至解答中。

若當前`s`長度仍然小於`n`的話，我們則分別append '0', '1'來繼續遞迴下去。