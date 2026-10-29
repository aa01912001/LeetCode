Problem Number: 3997. Count Dominant Nodes in a Binary Tree

Difficulty: `Medium`

## Problem Description

You are given the `root` of a **complete binary tree**.

A node `x` is called **dominant** if its value is equal to the maximum value among all nodes in the **subtree** rooted at `x`.

Return the number of dominant nodes in the tree.


**Example 1:**
![圖片](https://hackmd.io/_uploads/HyoV0Te6zx.png)
```
Input: root = [5,3,8,2,4,7,1]

Output: 5

Explanation:

- The leaf nodes with values 2, 4, 7, and 1 are dominant.
- The node with value 8 is dominant because its value is the maximum value in its subtree [8, 7, 1].
- Thus, the answer is 5.

```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 10^5]`.
- `1 <= Node.val <= 10^9`
- The tree is guaranteed to be a complete binary tree.

**Intuition:**

We can use DFS to find the maximum value in each subtree and check if the current node's value is greater than or equal to it.