題號: 951. Flip Equivalent Binary Trees
難度: Medium

## 問題描述

For a binary tree **T**, we can define a **flip operation** as follows: choose any node, and swap the left and right child subtrees.

A binary tree **X** is flip equivalent to a binary tree **Y** if and only if we can make **X** equal to **Y** after some number of flip operations.

Given the roots of two binary trees `root1` and `root2`, return `true` if the two trees are flip equivalent or `false` otherwise.
 

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2018/11/29/tree_ex.png)
```
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
```


**Constraints:**

- The number of nodes in each tree is in the range `[0, 100]`.
- Each tree will have **unique node values** in the range `[0, 99]`.

---
## 解決思路

此題我們可以藉由遞迴的方式，某節點的左右子樹是否有可能經由flip操作變為相同。

首先，我們需要比較兩個跟節點是否皆為空，或是其值皆相等，否則返回false，之後可分為兩種情況：

1. `root1`之左子樹與`root2`之左子樹為**Flip Equivalent Binary Trees**，並且`root1`之右子樹與`root2`之右子樹也為**Flip Equivalent Binary Trees**。

2. `root1`之左子樹與`root2`之右子樹為**Flip Equivalent Binary Trees**，並且`root1`之右子樹與`root2`之左子樹也為**Flip Equivalent Binary Trees**。

以上兩種情形都代表兩棵樹可成為**Flip Equivalent Binary Trees**，因此我們遞迴之返回值應該如下：

```cpp=
return (flipEquiv(root1->left, root2->left) && (flipEquiv(root1->right, root2->right))) || (flipEquiv(root1->left, root2->right) && (flipEquiv(root1->right, root2->left)));
```

藉由反覆考量左右子樹之情形，即可返回最終確認值。