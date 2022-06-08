題號: 99. Recover Binary Search Tree
難度: Medium

## 問題描述

You are given the `root` of a binary search tree (BST), where the values of **exactly** two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

**Example 1:**
![image alt](https://assets.leetcode.com/uploads/2020/10/28/recover1.jpg)
```
Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
```
**Constraints:**

- The number of nodes in the tree is in the range `[2, 1000]`.
- `-2^31 <= Node.val <= 2^31 - 1`

---
## 解決思路

首先我們可以知道BST的inorder的一定是一個increasing sequence，假設我們將其中兩個節點交換，代表有較大值往前挪，較小值往後挪，例子如下：

origin：
1 < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9


after swapping 3 and 6：
1 < 2 < 6 > 4 < 5 > 3 < 7 < 8 < 9
  
透過觀察我們可以發現，第一個被交換的節點(較大的那個)其後一個節點值會小於她，而第二個被交換的節點(較小的那個)其節點值會小於前一個節點，因此程式中我們只要利用inorder遞迴遍歷此sequence並根據上述條件將兩個被交換的節點位置儲存起來，並於最後交換即可。