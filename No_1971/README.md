題號: 1971. Find if Path Exists in Graph

難度: Easy

## 問題描述

There is a **bi-directional** graph with `n` vertices, where each vertex is labeled from `0` to `n - 1` (**inclusive**). The edges in the graph are represented as a 2D integer array `edges`, where each `edges[i] = [ui, vi]` denotes a bi-directional edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by **at most one** edge, and no vertex has an edge to itself.

You want to determine if there is a **valid path** that exists from vertex `start` to vertex `end`.

Given `edges` and the integers `n`, `start`, and `end`, return `true` if there is a **valid path** from `start` to `end`, or `false` otherwise.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png)

```
Input: n = 3, edges = [[0,1],[1,2],[2,0]], start = 0, end = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
```

**Constraints:**

- `1 <= n <= 2 * 10^5`
- `0 <= edges.length <= 2 * 10^5`
- `edges[i].length == 2`
- `0 <= ui, vi <= n - 1`
- `ui != vi`
- `0 <= start, end <= n - 1`
- There are no duplicate edges.
- There are no self edges.

---
## 解決思路

此題我們只需要使用union-find的策略找出所有的component，最後只要判斷`start`、`end`是否同屬於一個component即可。







