題號: 1361. Validate Binary Tree Nodes

難度: Medium

## 問題描述

You have `n` binary tree nodes numbered from `0` to `n - 1` where node `i` has two children `leftChild[i]` and `rightChild[i]`, return `true` if and only if **all** the given nodes form **exactly one** valid binary tree.

If node `i` has no left child then `leftChild[i]` will equal `-1`, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

**Example 1:**

![image alt](https://assets.leetcode.com/uploads/2019/08/23/1503_ex1.png)

```
Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
```

**Constraints:**

- `1 <= n <= 10^4`
- `leftChild.length == rightChild.length == n`
- `-1 <= leftChild[i], rightChild[i] <= n - 1`
---
## 解決思路

此題我們只要去計算每個節點的in-degree後，最後判斷in-degree為0個節點是否正好為一個(代表root)，而其他節點的in-degree皆等於1即可。而程式中我們利用union find的策略來找出此圖的component個數，以確保tree只有一棵。







