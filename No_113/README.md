題號: 113. Path Sum II
難度: Medium

## 問題描述
Given the `root` of a binary tree and an integer `targetSum`, return all **root-to-leaf** paths where the sum of the node values in the path equals `targetSum`. Each path should be returned as a list of the node **values**, not node references.

A **root-to-leaf** path is a path starting from the root and ending at any leaf node. A **leaf** is a node with no children.

**Example 1:**
![](https://hackmd.io/_uploads/ryp4c2q1a.jpg)
```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5000]`.
- `-1000 <= Node.val <= 1000`
- `-1000 <= targetSum <= 1000`

## 解決思路
此題我們透過DFS的方式將所有路徑進行遍歷，並進行節點值的累加，若當前節點為leaf且路徑和為`targetSum`，我們則將當前路徑放入至解答中。