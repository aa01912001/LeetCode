題號: 1791. Find Center of Star Graph

難度: Medium

## 問題描述

There is an undirected **star** graph consisting of n nodes labeled from `1` to `n`. A star graph is a graph where there is one **center** node and **exactly** `n - 1` edges that connect the center node with every other node.

You are given a 2D integer array `edges` where each `edges[i] = [ui, vi]` indicates that there is an edge between the nodes `ui` and `vi`. Return the center of the given star graph.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/02/24/star_graph.png)

```
Input: edges = [[1,2],[2,3],[4,2]]
Output: 2
Explanation: As shown in the figure above, node 2 is connected to every other node, so 2 is the center.
```

**Constraints:**

- `3 <= n <= 10^5`
- `edges.length == n - 1`
- `edges[i].length == 2`
- `1 <= ui, vi <= n`
- `ui != vi`
- The given `edges` represent a valid star graph..

---
## 解決思路

此題我們只要去計算每個節點的`degree`是多少後，找出`degree`為`n-1`的節點即可。