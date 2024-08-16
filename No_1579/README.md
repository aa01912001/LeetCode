題號: 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
難度: Hard

## 問題描述
Alice and Bob have an undirected graph of n nodes and three types of edges:

- Type 1: Can be traversed by Alice only.
- Type 2: Can be traversed by Bob only.
- Type 3: Can be traversed by both Alice and Bob.

Given an array `edges` where `edges[i] = [typei, ui, vi]` represents a bidirectional edge of type `typei` between nodes `ui` and `vi`, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return `-1` if Alice and Bob cannot fully traverse the graph.

**Example 1:**
![ex1](https://hackmd.io/_uploads/H1TaIv3cR.png)
```
Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
```

**Constraints:**

- `1 <= n <= 10^5`
- `1 <= edges.length <= min(10^5, 3 * n * (n - 1) / 2)`
- `edges[i].length == 3`
- `1 <= typei <= 3`
- `1 <= ui < vi <= n`
- All tuples `(typei, ui, vi)` are distinct.

**解決思路:**
此題我們知道對於type3的edge我們需要盡可能保留，讓Alice, Bob能夠復用。因此我們可以透過**union-find**的方式首先針對type3的edges來合併每個節點(component)，之後再分別針對type1, type2的edges將當前components進行合併，並且在union的過程中我們需要紀錄被挑選為保存edge的個數，以便於最後計算所有要被刪除的edge數量。

若最後發現Alice或Bob無法形成一個component數量只有一個graph，則返回-1。