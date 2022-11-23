題號: 1028. Recover a Tree From Preorder Traversal
難度: Hard

## 問題描述

We run a preorder depth-first search (DFS) on the `root` of a binary tree.

At each node in this traversal, we output `D` dashes (where `D` is the depth of this node), then we output the value of this node.  If the depth of a node is `D`, the depth of its immediate child is `D + 1`.  The depth of the `root` node is `0`.

If a node has only one child, that child is guaranteed to be **the left child**.

Given the output `traversal` of this traversal, recover the tree and return its `root`.

**Example 1:**
![](https://i.imgur.com/PwiHEgS.png)
```
Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
```

**Constraints:**

- The number of nodes in the original tree is in the range `[1, 1000]`.
- `1 <= Node.val <= 10^9`

---
## 解決思路

在此題中，假設當前深度為`depth`並給定一個`traversal`字串，我們可以將之分成三個部分:

1. 前綴數字(為root value)
2. 第一個至第二個前綴剛好有`depth+1`個`-`並接續數字的左子樹
3. 第二個前綴剛好有`depth+1`個`-`並接續數字至`traversal`最後的右子樹

舉例來說，當前深度為0，並給定`traversal`為`"1-2--3--4-5--6--7"`，我們可以知道`1`為當前的root value，`2--3--4`為左子樹部分，`5--6--7`為右子樹部分。

因此，透過上述規則並以遞迴剖析字串我們便可以輕易地建構出一顆合法的binary tree。