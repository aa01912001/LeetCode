題號: 1123. Lowest Common Ancestor of Deepest Leaves
難度: Medium

## 問題描述

Given the `root` of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that

- The node of a binary tree is a leaf if and only if it has no children
- The depth of the root of the tree is `0`. if the depth of a node is `d`, the depth of each of its children is `d + 1`.
- The lowest common ancestor of a set `S` of nodes, is the node `A` with the largest depth such that every node in `S` is in the subtree with root `A`.

**Example 1:**
![image alt](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/01/sketch1.png)
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
```
**Constraints:**

- The number of nodes in the tree will be in the range `[1, 1000]`.
- `0 <= Node.val <= 1000`
- The values of the nodes in the tree are **unique**.

---
## 解決思路

此題我們可以postorder的順序判斷左右子樹的深度，若皆為最深的話，則將當前節點設為欲返回的解答，此外我們也需要在遞迴程式碼中一開始的地方判斷是否為leaf且深度為最深，若是的話同樣將當前節點設為欲返回的解答，如此透過反覆遞迴即可得到最終的**Lowest Common Ancestor**。