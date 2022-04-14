題號: 1367. Linked List in Binary Tree
難度: Medium

## 問題描述

Given a binary tree `root` and a linked list with `head` as the first node. 

Return True if all the elements in the linked list starting from the `head` correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/02/12/sample_1_1720.png)
```
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
```

**Constraints:**

- The number of nodes in the tree will be in the range `[1, 2500]`.
- The number of nodes in the list will be in the range `[1, 100]`.
- `1 <= Node.val <= 100` for each node in the linked list and binary tree.

---
## 解決思路

此題我們可利用DFS策略來遍歷tree，程式中，我們將每個經歷過tree node皆作為list之開頭往下比較，因此只要藉由DFS遞迴即可將所有分支的可能性包含進去。

