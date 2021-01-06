題號: 1557. Minimum Number of Vertices to Reach All Nodes

難度: Medium

## 問題描述
Given a **directed acyclic graph**, with `n` vertices numbered from `0` to `n-1`, and an array edges where `edges[i] = [from_i, to_i]` represents a directed edge from node `from_i` to node `to_i`.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.


Example 1:

![](https://assets.leetcode.com/uploads/2020/07/07/untitled22.png)

```
Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
```

Constraints:

 - `2 <= n <= 10^5`
 - `1 <= edges.length <= min(10^5, n * (n - 1) / 2)`
 - `edges[i].length == 2`
 - `0 <= from_i, to_i < n`
 - `All pairs (from_i, to_i) are distinct.`




---
## 解決思路
此題只要找出所有Indegree為0的點就好，因為Indegree為0的點必定只能從他自己拜訪，所以必定在解答中，而其它Indegree不為0的點則可以由其它點拜訪，所以必不在解答中。
