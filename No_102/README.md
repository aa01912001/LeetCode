題號: 102. Binary Tree Level Order Traversal

難度: Medium

## 問題描述

Given the `root` of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```


**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-1000 <= Node.val <= 1000`


---
## 解決思路

此題只需要利用`queue<TreeNode*>`以BFS策略來遍歷每一個level即可。



