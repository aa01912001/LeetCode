題號: 919. Complete Binary Tree Inserter

難度: Medium

## 問題描述

A **complete binary tree** is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.

Design an algorithm to insert a new node to a complete binary tree keeping it complete after the insertion.

Implement the `CBTInserter` class:

- `CBTInserter(TreeNode root)` Initializes the data structure with the `root` of the complete binary tree.

- `int insert(int v)` Inserts a `TreeNode` into the tree with value `Node.val == val` so that the tree remains complete, and returns the value of the parent of the inserted `TreeNode`.

- `TreeNode get_root()` Returns the root node of the tree.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2021/08/03/lc-treeinsert.jpg)

```
Input
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
Output
[null, 1, 2, [1, 2, 3, 4]]

Explanation
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // return 1
cBTInserter.insert(4);  // return 2
cBTInserter.get_root(); // return [1, 2, 3, 4]
```

**Constraints:**

- The number of nodes in the tree will be in the range `[1, 1000]`.
- `0 <= Node.val <= 5000`
- `root` is a complete binary tree.
- `0 <= val <= 5000`
- At most `10^4` calls will be made to `insert` and `get_root`.

---
## 解決思路

此題我們可利用`vector<TreeNode*>`來儲存每個編號位置的節點。

在`CBTInserter`中，我們先將初始樹中的所有節點依順序放入vector中，同時記錄當前的編號。

在`insert`中，我們可利用當前編號除以二來找到父節點的編號，在將父節點從vector取出，並插入新節點。

在`get_root`中，我們只要返回vector中的第一個節點即可。