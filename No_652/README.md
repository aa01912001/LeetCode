題號: 652. Find Duplicate Subtrees

難度: Medium

## 問題描述

Given the `root` of a binary tree, return all **duplicate subtrees**.

For each kind of duplicate subtrees, you only need to return the root node of any **one** of them.

Two trees are **duplicate** if they have the **same structure** with the **same node values**.

 

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2020/08/16/e1.jpg)

```
Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
```

**Constraints:**

- `The number of the nodes in the tree will be in the range [1, 10^4]`
- `-200 <= Node.val <= 200`


---
## 解決思路

此題我們可利用`DFS`策略以`bottom-up`的方式來建立每個子樹的路徑字串，而對於這些路徑字串，我們使用`unordered_map<string, int>`來記錄其出現的次數，一旦發現此路逕字串為第二次出現，則將當前`root`加入到答案中。







