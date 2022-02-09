題號: 1382. Balance a Binary Search Tree
難度: Medium

## 問題描述

Given the `root` of a binary search tree, return a **balanced** binary search tree with the same node values. If there is more than one answer, return **any of them**.

A binary search tree is **balanced** if the depth of the two subtrees of every node never differs by more than `1`.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg)
```
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
```


**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `1 <= Node.val <= 10^5`


---
## 解決思路

此題我們可以先針對此BST做in-order遍歷，並將此順序依序存入`vector<int> nodes`中，之後我們採用二分法的方式將`nodes[mid]`作為root，而`nodes[left]~nodes[mid-1]`為左子樹節點，`nodes[mid+1]~nodes[right]`為右子樹節點，因此，左右子樹也可以以遞迴二分法的方式建構出來，最後形成的BST即為一顆高度平衡的樹。