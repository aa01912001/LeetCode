題號: 2055. Plates Between Candles
難度: Medium

## 問題描述

There is a long table with a line of plates and candles arranged on top of it. You are given a **0-indexed** string `s` consisting of characters `'*'` and `'|'` only, where a `'*'` represents a **plate** and a `'|'` represents a **candle**.

You are also given a **0-indexed** 2D integer array `queries` where `queries[i] = [lefti, righti]` denotes the **substring** `s[lefti...righti]` (**inclusive**). For each query, you need to find the **number** of plates **between candles** that are **in the substring**. A plate is considered **between candles** if there is at least one candle to its left **and** at least one candle to its right **in the substring**.

- For example, `s = "||**||**|*"`, and a query `[3, 8]` denotes the substring `"*||**|"`. The number of plates between candles in this substring is `2`, as each of the two plates has at least one candle **in the substring** to its left **and** right.

Return an integer array `answer` where `answer[i]` is the answer to the `ith` query.

**Example 1:**

![](https://i.imgur.com/NWEbixg.png)

```
Input: s = "***|**|*****|**||**|*", queries = [[1,17],[4,5],[14,17],[5,11],[15,16]]
Output: [9,0,0,0,0]
Explanation:
- queries[0] has nine plates between candles.
- The other queries have zero plates between candles.
```

**Constraints:**

- `3 <= s.length <= 10^5`
- `s` consists of `'*'` and `'|'` characters.
- `1 <= queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= lefti <= righti < s.length`

---
## 解決思路

此題我們可以先計算每一個索引位置的下一個右邊的candle位置與下一個左邊的索引位置，並將結果存於`nextRightCandle`和`nextLeftCandle`中，因此對於`queries[i]`來說我們只需要找尋`nextLeftCandle[queries[i][1]]`與`nextRightCandle[queries[i][0]]`之間的plate數量即可。

對於尋找某兩個位置的plate數量，我們可以使用prefix sum技巧將所有index 0 ~ index i之間的plate數量存於`LeftNumOfPlate[i]`中，之後針對位於index i、j的兩個candle位置，我們只需計算`LeftNumOfPlate[j]-LeftNumOfPlate[i]`即可得到兩者之間的plate數量。