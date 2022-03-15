題號: 979. Distribute Coins in Binary Tree
難度: Medium

## 問題描述

You are given the `root` of a binary tree with `n` nodes where each `node` in the tree has `node.val` coins. There are `n` coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return the **minimum** number of moves required to make every node have **exactly** one coin.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2019/01/18/tree1.png)
```
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
```

**Constraints:**

- The number of nodes in the tree is `n`.
- `1 <= n <= 100`
- `0 <= Node.val <= n`
- The sum of all `Node.val` is `n`.

---
## 解決思路

此題我們可以藉由DFS策略分別計算出左右子樹所需的coin數(程式中以`l`與`r`代表)，其中正值代表該子樹有多於節點數的coin，負值反之，隨後我們將`abs(l)`與`abs(r)`加入解答中，代表分發coin時會經過此節點的coin步數。

如此反覆操作至root時，即可得到分布所有coin所需的步數。