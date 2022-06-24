題號: 662. Maximum Width of Binary Tree
難度: Medium

## 問題描述

Given the `root` of a binary tree, return the **maximum width** of the given tree.

The **maximum width** of a tree is the maximum **width** among all levels.

The **width** of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is **guaranteed** that the answer will in the range of a **32-bit** signed integer.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/05/03/width1-tree.jpg)
```
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
```
**Constraints:**

- The number of nodes in the tree is in the range `[1, 3000]`.
- `-100 <= Node.val <= 100`

---
## 解決思路

此題我們只需要透過BFS策略來計算每一level中第一個與最後一個節點的距離即可，而在實作BFS的過程中，我們採用`queue<pair<TreeNode*, int>>`來儲存每一個非null節點與其在binary tree中的相應編號。

假設root編號為n，其左節點編號應為2n、右節點則為2n+1。
