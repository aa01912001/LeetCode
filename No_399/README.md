題號: 399. Evaluate Division

難度: Medium

## 問題描述

You are given an array of variable pairs `equations` and an array of real numbers `values`, where `equations[i] = [Ai, Bi]` and `values[i]` represent the equation `Ai / Bi = values[i]`. Each `Ai` or `Bi` is a string that represents a single variable.

You are also given some `queries`, where `queries[j] = [Cj, Dj]` represents the `jth` query where you must find the answer for `Cj / Dj = ?`.

Return the answers to all queries. If a single answer cannot be determined, return `-1.0`.

**Note:** The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

**Example 1:**

```
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
```

**Constraints:**

- `1 <= equations.length <= 20`
- `equations[i].length == 2`
- `1 <= Ai.length, Bi.length <= 5`
- `values.length == equations.length`
- `0.0 < values[i] <= 20.0`
- `1 <= queries.length <= 20`
- `queries[i].length == 2`
- `1 <= Cj.length, Dj.length <= 5`
- `Ai, Bi, Cj, Dj` consist of lower case English letters and digits.


---
## 解決思路

此題我們可利用圖論的方式來解。

假設 `equations = [["a","b"],["b","c"]], values = [2.0,3.0]`
對於`["a","b"]`來說，相當於`"a"`有一條權重為`2.0`的有向邊指向`"b"`，假設今天有一查詢為`["a","c"]`，那麼其解相當於找到一條從`"a"`到`"c"`的路徑，將其所有路徑權重相乘起來。證明如下:

query `["a","c"]` = a/c = a/b * b/c = 2\*3 = 6

所以在程式中我們首先利用`unordered_map<string, vector<pair<string, double>>> adj`的結構建立此DAG的adjacency list，同時記錄每個邊的權重。

之後利用DFS的策略找出每個query所要求的路徑即可。