題號: 958. Check Completeness of a Binary Tree
難度: Medium

## 問題描述

Given the `root` of a binary tree, determine if it is a complete binary tree.

In a **complete binary tree**, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between `1` and `2^h` nodes inclusive at the last level `h`.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2018/12/15/complete-binary-tree-1.png)
```
Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `1 <= Node.val <= 1000`

---
## 解決思路

此題我們可使用BFS策略來遍歷所有節點，途中只要我們經過第一個`nullptr`節點後，又出現其他非`nullptr`節點，則代表此樹不為complete。

