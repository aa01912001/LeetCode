題號: 106. Construct Binary Tree from Inorder and Postorder Traversal
難度: Medium

## 問題描述
Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return the binary tree.

**Example 1:**
![](https://i.imgur.com/OfwpjVs.png)
```
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

**Constraints:**

- `1 <= inorder.length <= 3000`
- `postorder.length == inorder.length`
- `-3000 <= inorder[i], postorder[i] <= 3000`
- `inorder` and `postorder` consist of **unique** values.
- Each value of `postorder` also appears in `inorder`.
- `inorder` is **guaranteed** to be the inorder traversal of the tree.
- `postorder` is **guaranteed** to be the postorder traversal of the tree.

---
## 解決思路
我們知道postorder的最後一個元素一定是root，因此我們可以透過此root值在inorder的index，輕易地將inorder與postorder切分為左右子樹的兩個部分，繼續遞迴建構。