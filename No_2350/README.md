題號: 2350. Shortest Impossible Sequence of Rolls
難度: Hard

## 問題描述
You are given an integer array `rolls` of length `n` and an integer `k`. You roll a `k` sided dice numbered from `1` to `k`, `n` times, where the result of the `ith` roll is `rolls[i]`.

Return the length of the **shortest** sequence of rolls so that there's no such subsequence in `rolls`.

A **sequence of rolls** of length `len` is the result of rolling a `k` sided dice `len` times.

**Example 1:**
```
Input: rolls = [4,2,1,2,3,3,2,4,1], k = 4
Output: 3
Explanation: Every sequence of rolls of length 1, [1], [2], [3], [4], can be taken from rolls.
Every sequence of rolls of length 2, [1, 1], [1, 2], ..., [4, 4], can be taken from rolls.
The sequence [1, 4, 2] cannot be taken from rolls, so we return 3.
Note that there are other sequences that cannot be taken from rolls.
```

**Constraints:**

- `n == rolls.length`
- `1 <= n <= 10^5`
- `1 <= rolls[i] <= k <= 10^5`

**解決思路:**
此題我們可以思考，若要判斷長度為n的sequence是否皆被包含在`rolls`，那麼對於每一個數字`1~k`來說，都要能夠在sequence的`index_1 ~ index_n`能夠被挑選。

我們需要初始化一個變數`count = 0`，其代表了sequence的當前index。

另外我們準備一個set，並從rolls開頭依序將數字加入到set中，如發現set已經包含了`k`個數字，那就代表`1~k`每一個數字在當前sequence的index是皆能夠被滿足的，因此我們將`count`加1並清空set後，再繼續觀察下一個index是否也能夠被滿足。

最後的`count`大小代表`rolls`最大能夠滿足的sequence長度，因此我們返回`count + 1`作為解答。
