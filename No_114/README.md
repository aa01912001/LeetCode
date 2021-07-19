題號: 114. Flatten Binary Tree to Linked List

難度: Easy

## 問題描述

Given the `root` of a binary tree, flatten the tree into a "linked list":

- The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
- The "linked list" should be in the same order as a **pre-order traversal** of the binary tree.
 

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)

```
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
```


**Constraints:**

- he number of nodes in the tree is in the range `[0, 2000]`.
- `-100 <= Node.val <= 100`


**Follow up:** Can you flatten the tree in-place (with `O(1)` extra space)?

---
## 解決思路

此題我們只需要以遞迴的方式將左子樹與右子樹做flatten後，再將左子樹接在root與右子樹中間即可。



