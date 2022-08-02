題號: 865. Smallest Subtree with all the Deepest Nodes
難度: Medium

## 問題描述

Given the `root` of a binary tree, the depth of each node is **the shortest distance to the root**.

Return *the smallest subtree* such that it contains **all the deepest nodes** in the original tree.

A node is called **the deepest** if it has the largest depth possible among any node in the entire tree.

The **subtree** of a node is a tree consisting of that node, plus the set of all descendants of that node.

**Example 1:**
![image alt](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png)
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest nodes of the tree.
Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
```
**Constraints:**

- The number of nodes in the tree will be in the range `[1, 500]`.
- `0 <= Node.val <= 500`
- The values of the nodes in the tree are **unique**.

---
## 解決思路

此題我們需要分別計算root之左右子樹的高度，若相等，則返回此root作為解答，否則，往較深的子樹繼續遞迴下去即可。
