題號: 98. Validate Binary Search Tree

難度: Medium

## 問題描述
Given the `root` of a binary tree, determine if it is a valid binary search tree (BST).

A **valid BST** is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

Example 1:

![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)
```
Input: root = [2,1,3]
Output: true
```

Example 2:

![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)
```
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```
---
## 解決思路
**一棵合法的binary search tree之inorder尋訪必可得到嚴格遞增的數列**，所以我們只需利用inorder traversal依序將節點的值存於vector中(即程式中的sort)，在判斷該vector從index 0 ~ last之值是否為嚴格遞增即可。