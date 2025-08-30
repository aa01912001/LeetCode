題號: 2415. Reverse Odd Levels of Binary Tree

難度: Medium

## 問題描述
Given the `root` of a **perfect** binary tree, reverse the node values at each **odd** level of the tree.

- For example, suppose the node values at level 3 are `[2,1,3,4,7,11,29,18]`, then it should become `[18,29,11,7,4,3,1,2]`.

Return the root of the reversed tree.

A binary tree is **perfect** if all parent nodes have two children and all leaves are on the same level.

The **level** of a node is the number of edges along the path between it and the root node.

**Example 1:**
![first_case1](https://hackmd.io/_uploads/SJUeh-g9ge.png)
```
Input: root = [2,3,5,8,13,21,34]
Output: [2,5,3,8,13,21,34]
Explanation: 
The tree has only one odd level.
The nodes at level 1 are 3, 5 respectively, which are reversed and become 5, 3.
```

**Constraints:**

- The number of nodes in the tree is in the range `[1, 2^14]`.
- `0 <= Node.val <= 10^5`
- `root` is a **perfect** binary tree.

**解決思路:**

此題可以很直觀的使用BFS策略來遍歷每一個level的節點，若當前為奇數level的話，我們再交換這些節點的值即可。