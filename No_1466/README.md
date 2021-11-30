題號: 1466. Reorder Routes to Make All Paths Lead to the City Zero

難度: Medium

## 問題描述

There are `n` cities numbered from `0` to `n - 1` and `n - 1` roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by `connections` where `connections[i] = [ai, bi]` represents a road from city `ai` to city `bi`.

This year, there will be a big event in the capital (city `0`), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city `0`. Return the **minimum** number of edges changed.

It's **guaranteed** that each city can reach city 0 after reorder.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/05/13/sample_1_1819.png)

```
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: Change the direction of edges show in red such that each node can reach the node 0 (capital).
```

**Constraints:**

- `2 <= n <= 5 * 10^4`
- `connections.length == n - 1`
- `connections[i].length == 2`
- `0 <= ai, bi <= n - 1`
- `ai != bi`


---
## 解決思路

此題我們我們可利用DFS的策略，從0開始進行遍歷。在DFS的過程中，我們將邊視為無向邊來進行深度搜尋，然而我們一旦發現有**非連向前DFS節點的邊**的話，就將解答值加1(因為此graph為tree，所以此邊必定要作reverse)，如此遍歷到最後即可得到所需最少的改變次數。