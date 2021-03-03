題號: 199. Binary Tree Right Side View

難度: Medium

## 問題描述
Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
![](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

Constraints:

1. The number of nodes in the tree is in the range `[0, 100]`.
2. `-100 <= Node.val <= 100`


---
## 解決思路

此題可利用DFS的方式以DRL之順序遍歷每個節點，其中對於每一個level之最右邊節點即為此level第一個出現的節點。