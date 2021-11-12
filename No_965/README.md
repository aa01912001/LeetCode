題號: 965. Univalued Binary Tree

難度: Easy

## 問題描述

A binary tree is **uni-valued** if every node in the tree has the same value.

Given the `root` of a binary tree, return `true` if the given tree is **uni-valued**, or `false` otherwise.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2018/12/28/unival_bst_1.png)

```
Input: root = [1,1,1,1,1,null,1]
Output: true
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 100]`.
- `0 <= Node.val < 100`

---
## 解決思路

此題我們只需要利用遞迴的方式，先判斷左右子樹是否為Univalued Binary Tree後，再去比較root與其左右子節點是否有相同的數值即可。







