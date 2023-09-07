題號: 110. Balanced Binary Tree
難度: Easy

## 問題描述
Given a binary tree, determine if it is **height-balanced**.

**Example 1:**
![](https://hackmd.io/_uploads/r1gVyAIR2.jpg)
```
Input: root = [3,9,20,null,null,15,7]
Output: true
```
**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-10^4 <= Node.val <= 10^4`

## 解決思路
此題我們採用DFS策略，不斷去找出左右子樹的高度，若高度差大於1，我們就將解答改為false。
