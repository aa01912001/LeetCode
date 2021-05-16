題號: 1373. Maximum Sum BST in Binary Tree

難度: Hard

## 問題描述

Given a **binary tree** `root`, the task is to return the maximum sum of all keys of **any** sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.

Example 1:

![image alt](https://assets.leetcode.com/uploads/2020/01/30/sample_1_1709.png)

```
Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
```

Constraints:

- The given binary tree will have between `1` and `40000` nodes.
Each node's value is between `[-4 * 10^4 , 4 * 10^4]`.


---
## 解決思路

此題我們需要利用遞迴來判斷每樹子樹是否為合法的BST。當某個節點的左右子樹為合法的BST，則需判斷**左子樹的最大值是否小於該節點值且右子樹之最小值是否大於該節點值**，並且記錄所有遍歷過的合法BST中最大的sum值即可。

