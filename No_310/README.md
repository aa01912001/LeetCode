題號: 310. Minimum Height Trees
難度: Medium

## 問題描述

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of `n` nodes labelled from `0` to `n - 1`, and an array of `n - 1` `edges` where `edges[i] = [ai, bi]` indicates that there is an undirected edge between the two nodes `ai` and `bi` in the tree, you can choose any node of the tree as the root. When you select a node `x` as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. `min(h)`)  are called **minimum height trees** (`MHTs`).

Return a list of all **MHTs**' root labels. You can return the answer in **any order**.

The **height** of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/09/01/e1.jpg)

```
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
```

**Constraints:**

- `1 <= n <= 2 * 10^4`
- `edges.length == n - 1`
- `0 <= ai, bi < n`
- `ai != bi`
- All the pairs ``(ai, bi)`` are distinct.
- The given input is **guaranteed** to be a tree and there will be **no repeated** edges.

---
## 解決思路

此題我們我們透過**Kahn’s algorithm**來進行**Topological Sorting**，在每一回合當中，我們將graph中的**leaf nodes**刪除，直至找到最後degree為1的節點即可。

此方法思想在於找到最靠近graph中間的那些節點，**這些節點作為root會使整個graph成為MHT**。

