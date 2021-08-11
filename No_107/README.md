題號: 107. Binary Tree Level Order Traversal II

難度: Medium

## 問題描述

Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
```

**Constraints:**

- `The number of nodes in the tree is in the range [0, 2000].
- `-1000 <= Node.val <= 1000`


---
## 解決思路

此題也是利用BFS的策略將每個level來從上到下進行遍歷，只是途中我們將每個level存在`stack<vector<int>>`中，最後在依序取出stack中的每個level即可得到bottom-up level order traversal。


