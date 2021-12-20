題號: 1372. Longest ZigZag Path in a Binary Tree

難度: Medium

## 問題描述

You are given the `root` of a binary tree.

A ZigZag path for a binary tree is defined as follow:

- Choose **any** node in the binary tree and a direction (right or left).
- If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
- Change the direction from right to left or from left to right.
- Repeat the second and third steps until you can't move in the tree.

Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest **ZigZag** path contained in that tree.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/01/22/sample_1_1702.png)
```
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
```


**Constraints:**

- The number of nodes in the tree is in the range `[1, 5 * 10^4]`.
- `1 <= Node.val <= 100`

---
## 解決思路

此題可利用DFS的策略去找出所有分支中，**ZigZag** path 最長的那條，過程中，我們需要去紀錄前一個DFS進行的方向，與當前**ZigZag** path長度。若前一個方向與下一個DFS方向相同，我們就應該將**ZigZag** path長度重新設為1，否則將此長度加1；最後若遇到空節點，則返回**ZigZag** path的長度即可。

如此，我們即可返回最長的**ZigZag** path的長度回去根節點。