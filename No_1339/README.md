題號: 1339. Maximum Product of Splitted Binary Tree
難度: Medium

## 問題描述

Given the `root` of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it **modulo** `10^9 + 7`.

**Note** that you need to maximize the answer before taking the mod and not after taking it.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/01/21/sample_1_1699.png)
```
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
```
**Constraints:**

- The number of nodes in the tree is in the range `[2, 5 * 10^4]`.
- `1 <= Node.val <= 10^4`

---
## 解決思路

此題我們首先計算出整顆樹的和(存於`total`)，之後利用DFS策略找出每個左子樹和(存於`left`)與右子樹和(存於`right`)後，再利用判斷`(total-left)*left`或`(total-right)*right`是否為Splitted Binary Tree的最大乘積即可。

