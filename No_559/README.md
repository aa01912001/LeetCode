題號: 559. Maximum Depth of N-ary Tree

難度: Easy

## 問題描述
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

Example 1:
![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)
```
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
```
---
## 解決思路
此題只需利用DFS遍歷每個節點並記錄歷史最深level即可。
