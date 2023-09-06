題號: 226. Invert Binary Tree
難度: Easy

## 問題描述
Given the `root` of a binary tree, invert the tree, and return its root.

**Example 1:**
![](https://hackmd.io/_uploads/BkfSL_SAh.jpg)
```
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]
```
**Constraints:**

- The number of nodes in the tree is in the range `[0, 100]`.
- `-100 <= Node.val <= 100`

## 解決思路
此題我們可透過遞迴不斷invert左右子樹，之後再將root之左右節點交換即可。
