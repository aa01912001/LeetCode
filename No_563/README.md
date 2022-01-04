題號: 563. Binary Tree Tilt
難度: Easy

## 問題描述

Given the `root` of a binary tree, return the sum of every tree node's **tilt**.

The **tilt** of a tree node is the **absolute difference** between the sum of all left subtree node **values** and all right subtree node **values**. If a node does not have a left child, then the sum of the left subtree node **values** is treated as 0. The rule is similar if the node does not have a right child.

 

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/10/20/tilt1.jpg)
```
Input: root = [1,2,3]
Output: 1
Explanation: 
Tilt of node 2 : |0-0| = 0 (no children)
Tilt of node 3 : |0-0| = 0 (no children)
Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so sum is 2; right subtree is just right child, so sum is 3)
Sum of every tilt : 0 + 0 + 1 = 1
```


**Constraints:**

- The number of nodes in the tree is in the range `[0, 10^4]`.
- `-1000 <= Node.val <= 1000`

---
## 解決思路

此題我們只要藉由DFS來找出左右子樹的sum後，過程中再將左右子樹的絕對差值加入至解答中即可。