題號: 2583. Kth Largest Sum in a Binary Tree
難度: Medium

## 問題描述
You are given the `root` of a binary tree and a positive integer `k`.

The **level sum** in the tree is the sum of the values of the nodes that are on the **same** level.

Return the `kth` **largest** level sum in the tree (not necessarily distinct). If there are fewer than `k` levels in the tree, return `-1`.

**Note** that two nodes are on the same level if they have the same distance from the root.

**Example 1:**
![](https://hackmd.io/_uploads/rJ8PaVHD2.png)
```
Input: root = [5,8,9,2,1,3,7,4,6], k = 2
Output: 13
Explanation: The level sums are the following:
- Level 1: 5.
- Level 2: 8 + 9 = 17.
- Level 3: 2 + 1 + 3 + 7 = 13.
- Level 4: 4 + 6 = 10.
The 2nd largest level sum is 13.
```
**Constraints:**

- The number of nodes in the tree is `n`.
- `2 <= n <= 10^5`
- `1 <= Node.val <= 10^6`
- `1 <= k <= n`

## 解決思路
此題我們只需要利用BFS策略對此樹進行level order的加總，並利用min heap來記錄前`k`大的level sum即可。

最後，若heap大小小於`k`，則返回-1，否則返回top值。