題號: 236. Lowest Common Ancestor of a Binary Tree
難度: Medium

## 問題描述
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the `definition of LCA on Wikipedia`: “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow **a node to be a descendant of itself**).”

**Example 1:**
![](https://hackmd.io/_uploads/S1bb8yJ1T.png)
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

**Constraints:**

- The number of nodes in the tree is in the range `[2, 10^5]`.
- `-10^9 <= Node.val <= 10^9`
- All `Node.val` are **unique**.
- `p != q`
- `p` and `q` will exist in the tree.

## 解決思路
此題我們只需要利用DFS的方式判斷，左右子樹是否皆存在目標節點即可。

若當前`root`等於`p`或`q`其中一個，那麼它一定是兩者的Lowest Common Ancestor，我們直接返回`root`即可。

否則若其左右子樹皆含有`p`或`q`，那麼`root`同樣必定是兩者的Lowest Common Ancestor，我們也可以直接返回`root`。

假設上述兩個cases都不成立，那我們就只能將該子樹是否含有目標節點的資訊給上層。