題號: 1448. Count Good Nodes in Binary Tree

難度: Medium

## 問題描述
Given a binary tree `root`, a node X in the tree is named **good** if in the path from root to X there are no nodes with a value greater than X.

Return the number of **good** nodes in the binary tree.

Example 1:
![](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)

```
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

Constraints:

- The number of nodes in the binary tree is in the range `[1, 10^5]`.
- Each node's value is between `[-10^4, 10^4]`

---
## 解決思路

此題直接直接用DFS在遍歷每個節點同時用一個`pathMax`變數紀錄當前路徑最大的值即可。一旦發現當前節點值大於等於`pathMax`，即將`pathMax`更新為當前節點值，並將返回值加1。