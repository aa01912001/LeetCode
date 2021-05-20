題號: 515. Find Largest Value in Each Tree Row

難度: Medium

## 問題描述

Given the `root` of a binary tree, return an array of the largest value in each row of the tree **(0-indexed)**.

Example 1:

![image alt](https://assets.leetcode.com/uploads/2020/08/21/largest_e1.jpg)

```
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
```

Constraints:

- The number of nodes in the tree will be in the range `[0, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`


---
## 解決思路

此題可以透過DFS(或BFS)的策略來遍歷每個節點，同時記載每個level上最大的節點值。
