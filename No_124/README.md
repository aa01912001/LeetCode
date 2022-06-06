題號: 124. Binary Tree Maximum Path Sum
難度: Hard

## 問題描述

A **path** in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence **at most once**. Note that the path does not need to pass through the root.

The **path sum** of a path is the sum of the node's values in the path.

Given the `root` of a binary tree, return the maximum **path sum** of any **non-empty** path.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/10/13/exx2.jpg)
```
Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 3 * 10^4]`.
- `-1000 <= Node.val <= 1000`

---
## 解決思路

此題我們可透過DFS策略來分別取得包含左子節點的最大路徑值與包含右子節點的最大路徑值，之後將當前解答值與下列四種情況比較並更新：

1. 包含左子節點的最大路徑值 + root->val
2. 包含右子節點的最大路徑值 + root->val
3. root->val
4. 包含左子節點的最大路徑值 + root->val + 包含右子節點的最大路徑值

其中，第4項是為了將橫向路徑考量進去。

之後返回1、2、3項中最大值給上層即可。

透過遞迴的層層考量，我們最終即可得到最大的路徑值。