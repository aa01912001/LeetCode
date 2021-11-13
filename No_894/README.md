題號: 894. All Possible Full Binary Trees

難度: Medium

## 問題描述

Given an integer `n`, return a list of all possible **full binary trees** with `n` nodes. Each node of each tree in the answer must have `Node.val == 0`.

Each element of the answer is the root node of one possible tree. You may return the final list of trees in **any order**.

A **full binary tree** is a binary tree where each node has exactly `0` or `2` children.

**Example 1:**

![image alt](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/08/22/fivetrees.png)

```
**Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
```

**Constraints:**

- `1 <= n <= 20`

---
## 解決思路

此題我們採用DP的策略配合遞迴去解。

程式中我們使用`unordered_map<int, vector<TreeNode*>> hmap`的結構來儲存不同`n`值的解，而對於右子樹的節點個數可以隨著左子樹的節點個數去遞迴計算。

舉例來說，假設我們要建構一顆節點數為`n`的**full binary tree**，那麼因為右子樹必定要有一顆以上的節點，所以左節點的個數可能為`i=1、3、5、...、n-2`，因此右子樹相對應的個數為`n-1-i`。

我們只要將可能的每一種左右子樹節點變化建構出來並與root相連後，就可以得到所有節點樹為`n`的**full binary tree**(每一個可能的**full binary tree**皆須放入`hmap[n]`中後並返回)。









