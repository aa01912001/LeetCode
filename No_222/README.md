題號: 222. Count Complete Tree Nodes
難度: Medium

## 問題描述

Given the `root` of a **complete** binary tree, return the number of the nodes in the tree.

According to **Wikipedia**, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between `1` and `2^h` nodes inclusive at the last level `h`.

Design an algorithm that runs in less than `O(n)` time complexity.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2021/01/14/complete.jpg)
```
Input: root = [1,2,3,4,5,6]
Output: 6
```

**Constraints:**

- The number of nodes in the tree is in the range `[0, 5 * 10^4]`.
- `0 <= Node.val <= 5 * 10^4`
- The tree is guaranteed to be **complete**.


---
## 解決思路

此題我們可透過遞迴的方式，每次針對`root`去計算其左傾高度(設為`lh`)及右傾高度(設為`rh`)，若發現`lh == rh`則代表包含當前`root`之tree為full binary tree，因此我們返回此tree之節點個數(`2^(lh+1)-1`)，否則透過遞迴往下計算(`countNodes(root->left) + countNodes(root->right) + 1`)，如此遞迴最後即可返回整顆complete tree之節點個數。

其計算複雜度只需O(log(n))*O(log(n))

