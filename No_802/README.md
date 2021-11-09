題號: 802. Find Eventual Safe States

難度: Medium

## 問題描述

There is a directed graph of n nodes with each node labeled from `0` to `n - 1`. The graph is represented by a **0-indexed** 2D integer array `graph` where `graph[i]` is an integer array of nodes adjacent to node `i`, meaning there is an edge from node `i` to each node in `graph[i]`.

A node is a **terminal node** if there are no outgoing edges. A node is a **safe node** if every possible path starting from that node leads to a **terminal node**.

Return an array containing all the **safe nodes** of the graph. The answer should be sorted in **ascending** order.

**Example 1:**

![image alt](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png)

```
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
```

**Constraints:**

- `n == graph.length`
- `1 <= n <= 10^4`
- `0 <= graph[i].length <= n`
- `0 <= graph[i][j] <= n - 1`
- `graph[i]` is sorted in a strictly increasing order.
- The graph may contain self-loops.
- The number of edges in the graph will be in the range `[1, 4 * 10^4]`.

---
## 解決思路

此題我們需要針對每個節點來判斷他是否屬於環路徑的節點，所以對於每個節點我們都賦予它一個label，其中:

0: 位拜訪節點
1: safe節點
2: unsafe節點

對於每個位拜訪的節點我們可利用DFS策略來對所有可能的路徑進行搜尋，一旦發現有路徑連到safe節點，我們則返回true，代表此路徑為合法，一但所有可能的路徑接返回true我們則將此節點label設為1。否則若有路徑連到unsafe節點，則將此節點label設為2。

最後我們只需要所有label為1的節點取出並返回即可。







