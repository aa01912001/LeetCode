題號: 1483. Kth Ancestor of a Tree Node
難度: Hard

## 問題描述
You are given a tree with `n` nodes numbered from `0` to `n - 1` in the form of a parent array `parent` where `parent[i]` is the parent of `ith` node. The root of the tree is node `0`. Find the `kth` ancestor of a given node.

The `kth` ancestor of a tree node is the `kth` node in the path from that node to the root node.

Implement the `TreeAncestor` class:

- `TreeAncestor(int n, int[] parent)` Initializes the object with the number of nodes in the tree and the parent array.

- `int getKthAncestor(int node, int k)` return the `kth` ancestor of the given node `node`. If there is no such ancestor, return `-1`.

**Example 1:**
![](https://hackmd.io/_uploads/H1vK224q2.png)
```
Input
["TreeAncestor", "getKthAncestor", "getKthAncestor", "getKthAncestor"]
[[7, [-1, 0, 0, 1, 1, 2, 2]], [3, 1], [5, 2], [6, 3]]
Output
[null, 1, 0, -1]

Explanation
TreeAncestor treeAncestor = new TreeAncestor(7, [-1, 0, 0, 1, 1, 2, 2]);
treeAncestor.getKthAncestor(3, 1); // returns 1 which is the parent of 3
treeAncestor.getKthAncestor(5, 2); // returns 0 which is the grandparent of 5
treeAncestor.getKthAncestor(6, 3); // returns -1 because there is no such ancestor
```
**Constraints:**

- `1 <= k <= n <= 5 * 10^4`
- `parent.length == n`
- `parent[0] == -1`
- `0 <= parent[i] < n` for all `0 < i < n`
- `0 <= node < n`
- There will be at most `5 * 10^4` queries.

## 解決思路
此題若我們單純使用`unordered_map<int, int>`來紀錄每個節點對應的父節點，再不斷進行父節點的向上更新，也能夠找出解答，但會遭遇TLE。

因此我們可以使用binery lifting的方式來對每個節點紀錄其祖先節點。

其中:

`bLifting[i][j]`為第`i`個節點的pow(2, i)-th祖先，而我們知道`2^i = 2^(i-1) + 2^(i-1)`，因此`bLifting[i][j]`的建構式為:

先令`n1 = blifting[i][j-1]`，則`bLifting[i][j] = blifting[n1][j-1]`

透過建立binery lifting的陣列，我們便可以輕易地找出節點`i`的任意順位之祖先節點。

例如尋找13th祖先節點的方式為:
先找8th、再向上找4th，最後再向上找1st祖先即可。