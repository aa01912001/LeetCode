題號: 103. Binary Tree Zigzag Level Order Traversal
難度: Medium

## 問題描述

Given the `root` of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)
```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```


**Constraints:**

- The number of nodes in the tree is in the range `[0, 2000]`.
- `-100 <= Node.val <= 100`

---
## 解決思路

此題我們可以利用`deque<TreeNode*>`執行BFS策略來解決，程式中有一個變數`level`用來儲存當前為第幾層，此時，`level`可分為兩種狀況：

1. `level`為偶數層：
    一律由deque前端取出節點，並將新節點插入後方

2. `level`為奇數層：
    一律由deque前後端取出節點，並將新節點插入前方
    
藉由如此反覆操作，我們最終即可得到此binary tree的**Zigzag Level Order**。
