題號: 1038. Binary Search Tree to Greater Sum Tree

難度: Medium

## 問題描述
Given the `root` of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

- The left subtree of a node contains only nodes with keys **less than** the node's key.
- The right subtree of a node contains only nodes with keys **greater than** the node's key.
- Both the left and right subtrees must also be binary search trees.


Example 1:
![](https://assets.leetcode.com/uploads/2019/05/02/tree.png)
```
Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
```
Constraints:


- The number of nodes in the tree is in the range `[1, 100]`.
- `0 <= Node.val <= 100`
- All the values in the tree are **unique**.
- `root` is guaranteed to be a valid binary search tree.

---
## 解決思路
此題我們可利用DFS以RDL次序來將節點由大到小遍歷，過程中利用一`tmp`變數來儲存每個節點的總和以便賦值。