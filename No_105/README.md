題號: 105. Construct Binary Tree from Preorder and Inorder Traversal
難度: Medium

## 問題描述

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return the binary tree.
![image alt](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

**Example 1:**

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```
**Constraints:**

- `1 <= preorder.length <= 3000`
- `inorder.length == preorder.length`
- `-3000 <= preorder[i], inorder[i] <= 3000`
- `preorder` and `inorder` consist of **unique** values.
- Each value of `inorder` also appears in `preorder`.
- `preorder` is **guaranteed** to be the preorder traversal of the tree.
- `inorder` is **guaranteed** to be the inorder traversal of the tree.

---
## 解決思路

此題我們可利用遞迴的方式來建構每個節點；我們可以知道當前`preorder`中的第一個元素一定是當下子樹之root，因此可以建構出具有該值的節點，之後我們在`inorder`中找出root值的索引位置後，就可以輕易地在`preorder`與`inorder`中將接下來左右子樹的目標子陣列進行劃分，從而繼續遞迴建構。

舉例來說：

preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
我們知道root值為preorder[0] == 3，且其位於inorder之索引1的位置，因此：

左子樹之子陣列為：
    preorder[1]~preorder[1]
    inorder[0]~inorder[1]
    
右子樹之子陣列為：
    preorder[2]~preorder[n-1]
    inorder[2]~inorder[n-1]
