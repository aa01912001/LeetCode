題號: 235. Lowest Common Ancestor of a Binary Search Tree
難度: Medium

## 問題描述
Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the `definition of LCA on Wikipedia`: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**
![](https://hackmd.io/_uploads/r1OlmKr0h.png)
```
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
```
**Constraints:**

- The number of nodes in the tree is in the range `[2, 10^5]`.
- `-10^9 <= Node.val <= 10^9`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the BST.

## 解決思路
我採用DFS策略，不斷比較`root`值與`p`、`q`之值。

若當前`root`大於`p`、`q`，則我們往左子樹搜尋。
若當前`root`小於`p`、`q`，則我們往右子樹搜尋。

否則直接返回`root`即可(第一個遇到的值介於`p`、`q`的節點必為Lowest Common Ancestor)。
